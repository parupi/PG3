#include <cstdio>
#include <cmath>

// 抽象クラス IShape
class IShape {
public:
    virtual void Size() = 0; // 面積を求める純粋仮想関数
    virtual void Draw() const = 0; // 面積を表示する純粋仮想関数
    virtual ~IShape() {} // 仮想デストラクタ
};

// Circle クラス（円）
class Circle : public IShape {
public:
    Circle(double radius) : radius(radius), area(0) {}

    // 面積を計算
    void Size() override {
        area = 3.14 * radius * radius; // πr^2
    }

    // 面積を表示
    void Draw() const override {
        printf("円の面積: %.2f\n", area);
    }

private:
    double radius;
    double area;
};

// Rectangle クラス（矩形）
class Rectangle : public IShape {
public:
    Rectangle(double width, double height) : width(width), height(height), area(0) {}

    // 面積を計算
    void Size() override {
        area = width * height; // 縦×横
    }

    // 面積を表示
    void Draw() const override {
        printf("矩形の面積: %.2f\n", area);
    }

private:
    double width;
    double height;
    double area;
};

int main() {
    // 円と矩形のインスタンスを生成
    IShape* circle = new Circle(5.0);   // 半径5の円
    IShape* rectangle = new Rectangle(4.0, 3.0); // 幅4、高さ3の矩形

    // 面積を計算して表示
    circle->Size();
    circle->Draw();

    rectangle->Size();
    rectangle->Draw();

    // メモリ解放
    delete circle;
    delete rectangle;

    return 0;
}
