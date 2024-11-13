#include <iostream>
#include <cstdio>
#include <functional>

class Enemy {
public:
    Enemy() : currentState(&Enemy::approach) {}

    // 状態遷移の関数
    void update() {
        (this->*currentState)();
    }

private:
    // 各状態を表すメンバ関数
    void approach() {
        printf("敵が接近中...\n");
        currentState = &Enemy::shoot; // 次の状態に遷移
    }

    void shoot() {
        printf("敵が射撃中！\n");
        currentState = &Enemy::retreat; // 次の状態に遷移
    }

    void retreat() {
        printf("敵が離脱中...\n");
        currentState = &Enemy::approach; // 最初の状態に戻る
    }

    // 現在の状態を指すメンバ関数ポインタ
    void (Enemy::* currentState)();
};

int main() {
    Enemy enemy;

    // 何回か状態を更新してみる
    for (int i = 0; i < 6; ++i) {
        enemy.update();
    }

    return 0;
}
