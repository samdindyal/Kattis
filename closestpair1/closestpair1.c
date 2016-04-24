#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10000

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
void quick_sort_by_x(Point*, int, int);
void quick_sort_by_y(Point*, int, int);

int main(void) {
	int num_points = 1;
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
		quick_sort_by_x(points, 0, num_points-1);
		PointDifference *solution;

        solution = calculate_closest_pair_recursive(points, num_points);

		printf("%.2f %.2f %.2f %.2f\n", solution->p1.x, solution->p1.y, solution->p2.x, solution->p2.y);
	}
	return 0;
}


float calculate_distance(Point *p1, Point *p2) {
	float dx = (p1->x - p2->x),
	 dy = (p1->y - p2->y);
	return sqrt((dx*dx) + (dy*dy));
}

void quick_sort_by_x(Point *array, int lower_bound, int upper_bound) {
  int pivot, i, j;
  Point temp;

  if (lower_bound < upper_bound) {
    pivot = lower_bound;
    i = lower_bound;
    j = upper_bound;

    while (i < j) {
      while (array[i].x <= array[pivot].x && i < upper_bound)
        i++;
      while (array[j].x > array[pivot].x)
        j--;
      if (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }

    temp = array[pivot];
    array[pivot] = array[j];
    array[j] = temp;

    quick_sort_by_x(array, lower_bound, j - 1);
    quick_sort_by_x(array, j + 1, upper_bound);
  }
}

void quick_sort_by_y(Point *array, int lower_bound, int upper_bound) {
  int pivot, i, j;
  Point temp;

  if (lower_bound < upper_bound) {
    pivot = lower_bound;
    i = lower_bound;
    j = upper_bound;

    while (i < j) {
      while (array[i].y <= array[pivot].y && i < upper_bound)
        i++;
      while (array[j].y > array[pivot].y)
        j--;
      if (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }

    temp = array[pivot];
    array[pivot] = array[j];
    array[j] = temp;

    quick_sort_by_y(array, lower_bound, j - 1);
    quick_sort_by_y(array, j + 1, upper_bound);
  }
}


PointDifference* calculate_closest_pair_brute_force(Point *points, int n) {

	PointDifference *minimum_difference, *current_difference;
	minimum_difference = (PointDifference*)malloc(sizeof(PointDifference));
	current_difference = (PointDifference*)malloc(sizeof(PointDifference));

	minimum_difference->difference = MAX;

	for (int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++)
		{
			current_difference->difference = calculate_distance(&(points[i]), &(points[j]));
			current_difference->p1 = points[i];
			current_difference->p2 = points[j];

			if (current_difference->difference < minimum_difference->difference)
				*minimum_difference = *current_difference;
		}

	return minimum_difference;
}

PointDifference* calculate_closest_pair_recursive(Point *points, int n) {
	if (n <= 10)
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
	{
			if (fabs(points[i].x - median.x) < min->difference)
			{
				closer_points[size] = points[i];
				size++;
			}
	}

	quick_sort_by_y(closer_points, 0, size-1);

	PointDifference *current_distance;
	current_distance = (PointDifference*)malloc(sizeof(PointDifference));
	current_distance->difference = MAX;

	for (int i = 0; i < size-1; i++)
	{
		current_distance->p1 = closer_points[i];
		for (int k = i+1; k < size && fabs(closer_points[k].y - closer_points[i].y) < min->difference; k++)
		{
			current_distance->p2 = closer_points[k];
			current_distance->difference = calculate_distance(&closer_points[k], &closer_points[i]);

			if (current_distance->difference < min->difference)
			{
				min = current_distance;
				current_distance = (PointDifference*)malloc(sizeof(PointDifference));
			}
		}
	}

	return min;
}
