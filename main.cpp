#include <cstdio>

// 2つの異なる型 T1, T2 に対応するクラステンプレート
template <typename T1, typename T2>
class Comparator {
public:
    // コンストラクタで2つの値を受け取る
    Comparator(T1 a, T2 b) : value1(a), value2(b) {}

private:
    T1 value1;
    T2 value2;
public:
    // Min関数：2つの値のうち小さい方を返す（共通の型にキャストして比較）
    auto Min() const -> decltype(value1 < value2 ? value1 : value2) {
        return (value1 < value2) ? value1 : value2;
    }
};

int main() {
    // int型とint型のインスタンス
    Comparator<int, int> intIntComp(10, 20);
    printf("int型とint型の小さい値: %d\n", intIntComp.Min());

    // int型とfloat型のインスタンス
    Comparator<int, float> intFloatComp(15, 7.2f);
    printf("int型とfloat型の小さい値: %.2f\n", intFloatComp.Min());

    // float型とdouble型のインスタンス
    Comparator<float, double> floatDoubleComp(10.5f, 20.75);
    printf("float型とdouble型の小さい値: %.2f\n", floatDoubleComp.Min());

    // double型とint型のインスタンス
    Comparator<double, int> doubleIntComp(5.5, 3);
    printf("double型とint型の小さい値: %.2f\n", doubleIntComp.Min());

    // int型とdouble型のインスタンス
    Comparator<int, double> intDoubleComp(8, 10.1);
    printf("int型とdouble型の小さい値: %.2f\n", intDoubleComp.Min());

    // double型とdouble型のインスタンス
    Comparator<double, double> doubleDoubleComp(7.34, 10.1);
    printf("double型とdouble型の小さい値: %.2f\n", intDoubleComp.Min());

    return 0;
}
