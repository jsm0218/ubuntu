#include <stdio.h>

int main() {
	int first, second;
	
	scanf("%d", &first); // (1)
	scanf("%d", &second); // (2)

	printf("%d\n", first * (second % 10)); // (3)
	printf("%d\n", first * ((second % 100) / 10)); // (4)
	printf("%d\n", first * (second / 100)); // (5)
	printf("%d\n", first * second); // (6)

	return 0;
}
