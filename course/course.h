/**
 * @file course.h
 * @author Krish Krish (krishk17@mcmaster.ca)
 * @brief Header file for the course library.
 * @version 1
 * @date 2022-04-12
 *
 */
#include "student.h"
#include <stdbool.h>

/**
 * @brief A course struct that holds the name, code, total students and a list of students.
 *
 */
typedef struct _course
{
  char name[100];
  char code[10];
  Student *students;
  int total_students;
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course *course);
Student *passing(Course *course, int *total_passing);
