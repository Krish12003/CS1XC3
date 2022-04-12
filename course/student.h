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
  char first_name[50]; /**< The first name of the student */
  char last_name[50];  /**< The last name of the student */
  char id[11];         /**< The id of the student */
  double *grades;      /**< A pointer to an array of grades of the student */
  int num_grades;      /**< The number of recorded grades for the student */
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student *generate_random_student(int grades);
