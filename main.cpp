#include <iostream>
#include <type_traits>

template <typename T>
T min(T a, T b) {
	if (a < b) {
		return static_cast<T>(a);;
	}
	else {
		return static_cast<T>(b);
	}
}

template<>
char min<char>(char a, char b) {
	printf ("数字以外は入力できません");
	return 0;
}

int main() {

	printf("%d\n", min<int>(114, 514));
	printf("%f\n", min<float>(11.4f, 51.4f));
	printf("%lf\n", min<double>(11.4, 51.4));
	printf("%c\n", min<char>('A', 'B'));

	return 0;
}