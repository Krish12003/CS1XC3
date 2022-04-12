/**
 * @file student.h
 * @author Krish Krish (krishk17@mcmaster.ca)
 * @brief Header file for the student library.
 * @version 1
 * @date 2022-04-12
 *
 */

/**
 * @brief A student struct that holds the name, id and grades of a student.
 *
 */
typedef struct _student
{
  char first_name[50];
  char last_name[50];
  char id[11];
  double *grades;
  int num_grades;
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student *generate_random_student(int grades);
