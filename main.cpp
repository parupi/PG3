#include <cstdio>

// 基底クラス：スマートフォン
class Smartphone {
public:
    virtual void ShowManufacturer() const = 0; // 純粋仮想関数（製造元を表示）
    virtual ~Smartphone() {}                   // 仮想デストラクタ
};

// 派生クラス：iPhone
class iPhone : public Smartphone {
public:
    void ShowManufacturer() const override {
        printf("iPhone の製造元: Apple\n");
    }
};

// 派生クラス：Galaxy
class Galaxy : public Smartphone {
public:
    void ShowManufacturer() const override {
        printf("Galaxy の製造元: Samsung\n");
    }
};

// 派生クラス：Xperia
class Xperia : public Smartphone {
public:
    void ShowManufacturer() const override {
        printf("Xperia の製造元: Sony\n");
    }
};

// 派生クラス：Pixel
class Pixel : public Smartphone {
public:
    void ShowManufacturer() const override {
        printf("Pixel の製造元: Google\n");
    }
};

int main() {
    // 各スマートフォンのインスタンスを生成
    Smartphone* iphone = new iPhone();
    Smartphone* galaxy = new Galaxy();
    Smartphone* xperia = new Xperia();
    Smartphone* pixel = new Pixel();

    // ポリモーフィズムを使用して、それぞれの「ShowManufacturer」メソッドを呼び出す
    iphone->ShowManufacturer();
    galaxy->ShowManufacturer();
    xperia->ShowManufacturer();
    pixel->ShowManufacturer();

    // メモリの解放
    delete iphone;
    delete galaxy;
    delete xperia;
    delete pixel;

    return 0;
}
