#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

// 指定した秒数後に関数を実行するSetTimeout関数
void SetTimeout(std::function<void(int*)> func, int second, int number) {
	Sleep(second * 1000);
	func(&number);
}

int main() {
	// ランダムシードの初期化
	srand(static_cast<unsigned int>(time(0)));

	//PFunc func;
	int userGuess;

	while (true) {
		// サイコロを振る
		int diceRoll = rand() % 6 + 1;

		printf("サイコロの目が奇数か偶数かあててください（奇数: 1, 偶数: 2）: ");

		scanf_s("%d", &userGuess);

		if (userGuess != 1 && userGuess != 2) {
			printf("1 (奇数) または2 (偶数) を入力してください。\n");
			continue;
		}

		// ラムダ式で判定ロジックを定義
		auto isEven = [userGuess](int* number) {
			if (*number % 2 == 0) {
				if (userGuess == 2) {
					printf("正解！ サイコロの出目は%dです\n", *number);
				} else {
					printf("不正解。 サイコロの出目は%dです\n", *number);
				}
			} else {
				if (userGuess == 1) {
					printf("正解！ サイコロの出目は%dです\n", *number);
				} else {
					printf("不正解。 サイコロの出目は%dです\n", *number);
				}
			}
			};

		//func = &isEven;
		SetTimeout(isEven, 3, diceRoll);

		printf("もう一度やりますか？ (はい: 1, いいえ: 0) : ");
		int playAgain;
		scanf_s("%d", &playAgain);

		if (playAgain != 1) {
			break;
		}
	}

	printf("\nゲームを終了します。ありがとうございました！\n");

	return 0;
}