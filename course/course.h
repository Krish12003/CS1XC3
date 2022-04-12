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
  char name[100];     /**< The name of the course */
  char code[10];      /**< The code of the course */
  Student *students;  /**< A pointer to an array of the students in the course */
  int total_students; /**< The number of students in the course */
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course *course);
Student *passing(Course *course, int *total_passing);
