#include <stdio.h>
	
void print_line_segment(int ax, int ay, int bx, int by) {
	//using Bresenham's line algorithm
	int dx, dy, D, y, x, i, j;
	char field[bx][by];
	
	for(i = 0; i < bx; i++) {
		for(j = 0; j < by; j++) {
			field[i][j] = ' ';
		}
	}
	
	printf("%d %d %d %d\n", ax, ay, bx, by);
	
	dx = bx - ax;
	dy = by - ay;
	
	if(dx >= dy) {
		D = 2*dy - dx;
		y = ay;
	
		for(x = ax; x <= bx; x++) {
			field[x][y] = 'x';
			if(D > 0) {
				y = y + 1;
				D = D - 2*dx;
			}
			D = D + 2*dy;
		}
	}
	
	else {
		D = 2*dx - dy;
		x = ax;
	
		for(y = ay; y <= by; y++) {
			field[x][y] = 'x';
			if(D > 0) {
				x = x + 1;
				D = D - 2*dy;
			}
			D = D + 2*dx;
		}
	}
	
	for(i = 0; i < bx; i++) {
		for(j = 0; j < by; j++) {
			printf("%c",field[i][j]);
		}
		printf("\n");
	}
}
		
	
	
int main(void) {
	int ax, ay, bx, by;
	
	printf("Zadaj x-ovu a y-ovu suradnicu prveho bodu:\n");
	scanf("%d %d", &ax, &ay);
	
	printf("Zadaj x-ovu a y-ovu suradnicu druheho bodu:\n");
	scanf("%d %d", &bx, &by);
		
	print_line_segment(ax, ay, bx, by);

}
