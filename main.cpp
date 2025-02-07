#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <thread>
#include <mutex>

std::vector<std::vector<int>> mapData; // マップデータを格納
std::mutex mtx; // データ競合を防ぐためのミューテックス

// CSVファイルを読み込む関数
void loadMap(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        std::string value;
        while (std::getline(iss, value, ',')) {
            row.push_back(std::stoi(value)); // 数字として変換して格納
        }

        std::lock_guard<std::mutex> lock(mtx); // マップデータへのアクセスを保護
        mapData.push_back(row);
    }

    file.close();
}

// マップデータを出力する関数
void printMap() {
    std::lock_guard<std::mutex> lock(mtx); // データアクセスを保護
    for (const auto& row : mapData) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string filename = "map.csv"; // マップデータファイル名

    // CSVファイルを読み込むスレッドを作成
    std::thread loader(loadMap, filename);

    // スレッドが完了するのを待機
    loader.join();

    // 読み込んだマップデータを出力
    printMap();

    return 0;
}
