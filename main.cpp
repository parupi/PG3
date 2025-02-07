#include <iostream>
#include <string>
#include <chrono>

int main() {
    // 100,000文字の'a'で初期化された文字列
    std::string largeString(100000, 'a');

    // コピー操作の時間計測
    auto startCopy = std::chrono::high_resolution_clock::now();
    std::string copiedString = largeString; // コピー
    auto endCopy = std::chrono::high_resolution_clock::now();
    auto copyDuration = std::chrono::duration_cast<std::chrono::microseconds>(endCopy - startCopy).count();

    // 移動操作の時間計測
    auto startMove = std::chrono::high_resolution_clock::now();
    std::string movedString = std::move(largeString); // 移動
    auto endMove = std::chrono::high_resolution_clock::now();
    auto moveDuration = std::chrono::duration_cast<std::chrono::microseconds>(endMove - startMove).count();

    // 結果を表示
    std::cout << "100,000文字を移動とコピーで比較しました。\n";
    std::cout << "コピー: " << copyDuration << "μs\n";
    std::cout << "移動: " << moveDuration << "μs\n";

    return 0;
}
