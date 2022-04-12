/**
 * @file course.c
 * @author Krish Krish (krishk17@mcmaster.ca)
 * @brief Implementations for the course library.
 * @version 1
 * @date 2022-04-12
 *
 */

#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/**

 *
 *
 * @brief Given pointer to a course and a pointer to a student, add the student to the course.
 *
 * @param course A pointer to a Course struct.
 * @param student a pointer to a Student struct
 */
void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  // If only one total student, the use calloc to allocate memory for one student array
  if (course->total_students == 1)
  {
    course->students = calloc(1, sizeof(Student));
  }
  // Else, allocate memory for all students using realloc - we need to realloc
  // because there were students previously in the array that still need to be stored
  else
  {
    course->students =
        realloc(course->students, course->total_students * sizeof(Student));
  }
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief Print the details of a course, then all students in a course.
 *
 * @param course A pointer to a Course struct.
 */
void print_course(Course *course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++)
    print_student(&course->students[i]);
}

/**
 * @brief Return the student with the highest average in the given course.
 *
 * @param course a pointer to a Course struct
 *
 * @return A pointer to a student.
 */
Student *top_student(Course *course)
{
  if (course->total_students == 0)
    return NULL;

  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];

  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average)
    {
      max_average = student_average;
      student = &course->students[i];
    }
  }

  return student;
}

/**
 * @brief Return a pointer to an array of students who passed the course.
 *
 * @param course a pointer to a Course struct
 * @param total_passing a pointer to an integer that will be set to the number of students that passed
 * the course.
 *
 * @return A pointer to an array of students.
 */
Student *passing(Course *course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;

  for (int i = 0; i < course->total_students; i++)
    if (average(&course->students[i]) >= 50)
      count++;

  passing = calloc(count, sizeof(Student));

  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++;
    }
  }

  *total_passing = count;

  return passing;
}