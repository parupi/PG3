#include <stdio.h>

float NormalWages(float time) {
	return 1072 * time;
}

float RecursionHourlyWages(float time) {
	if (time <= 1.0f) {
		return 100.0f;
	}
	return RecursionHourlyWages(time - 1) * 2.0f - 50.0f;
}

float RecursionTotalWages(float time) {
	if (time <= 1.0f) {
		return RecursionHourlyWages(1.0f);
	}
	return RecursionHourlyWages(time) + RecursionTotalWages(time - 1);
}

void WagesCalculation(float time) {
	if (NormalWages(time) < RecursionTotalWages(time)) {
		printf("%.0f時間だと再帰的賃金のほうが高い\n", time);
	}
	else {
		printf("%.0f時間だと一般的賃金のほうが高い\n", time);
	}
}

int main() {
	WagesCalculation(6.0f);
	WagesCalculation(7.0f);
	WagesCalculation(8.0f);
	WagesCalculation(9.0f);

	return 0;
}