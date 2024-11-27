#include <list>
#include <cstdio>

// 駅情報を保持する構造体
struct Station {
    int number;
    const char* name_jp;
    const char* name_en;
};

void printStations(const std::list<Station>& stations, const char* title) {
    printf("%s\n", title);
    for (const auto& station : stations) {
        printf("JY%02d: %s (%s)\n", station.number, station.name_jp, station.name_en);
    }
    printf("\n");
}

int main() {
    // 初期の1970年の駅リスト
    std::list<Station> stations = {
        {1, "東京", "Tokyo"}, {2, "神田", "Kanda"}, {3, "秋葉原", "Akihabara"},
        {4, "御徒町", "Okachimachi"}, {5, "上野", "Ueno"}, {6, "鶯谷", "Uguisudani"},
        {7, "日暮里", "Nippori"}, {9, "田端", "Tabata"}, {10, "駒込", "Komagome"},
        {11, "巣鴨", "Sugamo"}, {12, "大塚", "Otsuka"}, {13, "池袋", "Ikebukuro"},
        {14, "目白", "Mejiro"}, {15, "高田馬場", "Takadanobaba"}, {16, "新大久保", "Shin-Okubo"},
        {17, "新宿", "Shinjuku"}, {18, "代々木", "Yoyogi"}, {19, "原宿", "Harajuku"},
        {20, "渋谷", "Shibuya"}, {21, "恵比寿", "Ebisu"}, {22, "目黒", "Meguro"},
        {23, "五反田", "Gotanda"}, {24, "大崎", "Osaki"}, {25, "品川", "Shinagawa"},
        {26, "田町", "Tamachi"}, {27, "浜松町", "Hamamatsucho"}, {28, "新橋", "Shimbashi"},
        {29, "有楽町", "Yurakucho"}
    };

    // 1970年の駅リストを表示
    printStations(stations, "Station list for 1970:");

    // 1971年に西日暮里を追加
    stations.insert(std::next(stations.begin(), 7), { 8, "西日暮里", "Nishi-Nippori" });

    // 2019年の駅リストを表示
    printStations(stations, "Station list for 2019:");

    // 2020年に高輪ゲートウェイを追加
    stations.insert(std::next(stations.begin(), 26), { 30, "高輪ゲートウェイ", "TakanawaGateway" });

    // 2022年の駅リストを表示
    printStations(stations, "Station list for 2022:");

    return 0;
}
