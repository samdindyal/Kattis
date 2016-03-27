#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>

typedef struct Point {
	float x, y;
} Point;

typedef struct PointDifference {
	Point p1, p2;
	float difference;
} PointDifference;

float calculate_distance(Point*, Point*);
PointDifference* calculate_closest_pair_brute_force(Point*, int);
PointDifference* calculate_closest_pair_recursive(Point*, int);
int compareX(const void*, const void*);
int compareY(const void*, const void*);

int main(void) {
	int num_points;
	Point *points;

	while (num_points > 0)
	{
		if (!scanf("%d", &num_points))
			exit(1);
		if (num_points == 0)
			return 0;
		points = (Point*)malloc(num_points*sizeof(Point));
		for (int i = 0; i < num_points; i++)
			if (!scanf("%f %f", &(points[i].x), &(points[i].y)))
				exit(1);

		qsort(points, num_points, sizeof(Point), compareX);
		PointDifference *solution = calculate_closest_pair_recursive(points, num_points);
		printf("%.2f %.2f %.2f %.2f\n", solution->p1.x, solution->p1.y, solution->p2.x, solution->p2.y);
	}
	return 0;
}


float calculate_distance(Point *p1, Point *p2) {
	float dx = (p1->x - p2->x),
	 dy = (p1->y - p2->y);
	return sqrt((dx*dx) + (dy*dy));
}

int compareX(const void* _p1, const void* _p2) {
	Point *p1 = (Point*)_p1;
	Point *p2 = (Point*)_p2;
	return (p1->x - p2->x);
}

int compareY(const void* _p1, const void* _p2) {
	Point *p1 = (Point*)_p1;
	Point *p2 = (Point*)_p2;
	return (p1->y - p2->y);
}

PointDifference* calculate_closest_pair_brute_force(Point *points, int n) {
	
	PointDifference *minimum_difference, *current_difference;
	minimum_difference = (PointDifference*)malloc(sizeof(PointDifference));
	current_difference = (PointDifference*)malloc(sizeof(PointDifference));

	minimum_difference->difference = FLT_MAX;

	for (int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++)
		{
			current_difference->difference = calculate_distance(&(points[i]), &(points[j]));
			current_difference->p1 = points[j];
			current_difference->p2 = points[i];

			if (current_difference->difference < minimum_difference->difference)
				*minimum_difference = *current_difference;
		}

	return minimum_difference;
}

PointDifference* calculate_closest_pair_recursive(Point *points, int n) {
	if (n <= 3)
		return calculate_closest_pair_brute_force(points, n);
	
	int mid = n/2;
	PointDifference *left = calculate_closest_pair_recursive(points, mid);
	PointDifference *right = calculate_closest_pair_recursive(points + mid, n - mid);

	PointDifference *min;

	min = (left->difference < right->difference) ? left : right;
	Point median = points[mid];

	Point closer_points[n];

	int size = 0;

	for (int i = 0; i < n-1; i++)
		if (fabs(points[i].x - median.x) < min->difference)
		{
			closer_points[size] = points[i];
			size++;
		}

	qsort(closer_points, size, sizeof(Point), compareY);

	PointDifference *current_distance;
	current_distance = (PointDifference*)malloc(sizeof(PointDifference));
	current_distance->difference = FLT_MAX;

	for (int i = 0; i < size-1; i++)
		for (int k = i+1; k < size && fabs(closer_points[k].y - closer_points[i].y) < min->difference; k++)
		{
			current_distance->p1 = closer_points[k];
			current_distance->p2 = closer_points[i];
			current_distance->difference = calculate_distance(&closer_points[k], &closer_points[i]);

			if (current_distance->difference < min->difference)
			{
				min = current_distance;
				current_distance = (PointDifference*)malloc(sizeof(PointDifference));
			}
		}

	return min;
}

