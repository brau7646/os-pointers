// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;
    

    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);

    student.f_name = new char[128];
    student.l_name = new char[128];

    std::cout << "Please enter the student's first name: ";
    std::cin >> student.f_name;

    std::cout << "Please enter the student's last name: ";
    std::cin >> student.l_name;


    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 0, 134217728);
    std::cout << "\n";
    int i;
    for (i=0; i < student.n_assignments; i++)
    {
        std::string assignmentGrade = "Please enter grade for assignment " + std::to_string(i) + ": ";
        student.grades[i] = promptDouble(assignmentGrade,0.0,100.0);
    }

    std::cout <<"\nStudent: " << student.f_name << " " << student.l_name << " [" << std::to_string(student.id) << "]\n";


    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`
    calculateStudentAverage(&student,&average);
    float floatAverage = (float) average;
    std::cout <<"  Average grade: ";
    printf("%.*f", 1,floatAverage);
    std::cout<<"\n";
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int toReturn;
    while (true)
    {
        std::cout << message;
        std::cin >> toReturn;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(max,'\n');
            std::cout << "Sorry, I cannot understand your answer"<<std::endl;
        }
        else
        {
            break;
        }
    }
    return toReturn;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double;
    double toReturn;
    while (true)
    {
        std::cout << message;
        std::cin >> toReturn;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(max,'\n');
            std::cout << "Sorry, I cannot understand your answer"<<std::endl;
        }
        else
        {
            break;
        }
    }
    return toReturn;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    int i;
    double sum=0.0;
    Student student = *(Student *)object;
    for (i=0; i < student.n_assignments; i++)
    {
        sum = sum + student.grades[i];
    }
    
    *avg = sum/student.n_assignments;
    
}
