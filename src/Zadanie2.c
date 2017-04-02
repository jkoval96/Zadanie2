#include <stdio.h>
	
void print_line_segment(char ax, char ay, char bx, char by) {
	
	printf("%d %d %d %d", ax, ay, bx, by);
}
		
	
	
int main(void) {
	char ax, ay, bx, by;
	
	printf("Zadaj x-ovu a y-ovu suradnicu prveho bodu:\n");
	scanf("%d %d", &ax, &ay);
	
	printf("Zadaj x-ovu a y-ovu suradnicu druheho bodu:\n");
	scanf("%d %d", &bx, &by);
		
	print_line_segment(ax, ay, bx, by);
}
