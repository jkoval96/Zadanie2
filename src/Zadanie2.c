#include <stdio.h>
	
void print_line_segment(int ax, int ay, int bx, int by) {
	//using Bresenham's line algorithm
	int dx, dy, D, err, y, x, i, j;
	char field[bx][by];
	
	printf("%d %d %d %d\n", ax, ay, bx, by);
	
	dx = bx - ax;
	dy = by - ay;
	D = 2*dy - dx;
	y = ay;
	
	for(i = 0; i < ay; i++) {
		field[0][i] = '\n';
	}
	for(j = 0; j < ax; j++) {
		field[i][0] = 32;
	}
	for(x = ax; x <= bx; x++) {
		field[x][y] = 32;
		if(D > 0) {
			y = y + 1;
			field[x][y] = '\n';
			for(i = 0; i <= x; i++) {
				field[x][y] = 'x';
			}
			D = D - 2*dx;
		}
		D = D + 2*dy;
	}
	for(i = 0; i < bx; i++) {
		for(j = 0; j < by; j++) {
			printf("%c",field[i][j]);
		}
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
