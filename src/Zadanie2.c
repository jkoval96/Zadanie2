#include <stdio.h>
	
void print_line_segment(int ax, int ay, int bx, int by) {
	//using Bresenham's line algorithm
	printf("%d %d %d %d\n", ax, ay, bx, by);
}
		
	
	
int main(void) {
	int ax, ay, bx, by;
	
	printf("Zadaj x-ovu a y-ovu suradnicu prveho bodu:\n");
	scanf("%d %d", &ax, &ay);
	
	printf("Zadaj x-ovu a y-ovu suradnicu druheho bodu:\n");
	scanf("%d %d", &bx, &by);
		
	print_line_segment(ax, ay, bx, by);

}
