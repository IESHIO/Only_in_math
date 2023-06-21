#include <iostream>
#include <cmath>
using namespace std;
// В данном файле будет распологаться решение квадратных уравнений различными методами

int methods();
int crammers_rule();
int discriminant();
int fraction();
int trigonometry();
int demonstration();
int logarithmic();

int main()
{
    setlocale(LC_ALL, "ru");
    short int between,choose;
    cout << "Привет! \nДобро пожаловать в программу для решения уравнений для студентов!" << endl;
    cout << "Какое у тебя уравнение?" << endl;
    cout << "1 - линейное (ax+b=0) \n2 - квадратное (ax^2+bx+c=0)\n3 - биквадратное (f(x)/g(x)=0) \n";
    cout << "4 - тригонометрическое (sin x = a) \n5 - показательное (a^x = b)\n6 - логарифмическое (log⌄a x = b)" << endl;
    cin >> choose;

    switch (choose)
    {
    case 1:
        methods();
        break;

    case 2:
        methods();//реализовать всё в одной функции, но с постоянным выбором
        break;

    case 3:
        fraction();
        break;

    case 4:
       trigonometry();
        break;

    case 5:
        demonstration();
        break;

    case 6:
        logarithmic();
        break;


    default:
        cout << "уравнение пока что не реализовано" << endl;
        return 0;
    }

}

int methods()
{ 
    short int between;
    cout << "каким методом его нужно решить?" << endl;
    cout << "1 - дискриминант \n2 - Метод Краммера" << endl;
    cout << "3 - метод коэфицента" << endl;
    cin >> between;

    switch (between)
    {
    case 1:
        discriminant();
        break;

    case 2:
        crammers_rule();
        break;

    default:
        cout << "математическая операция не реализована" << endl;
        return 0;
    }
    
    return 0;
}



int discriminant()
{
    int D, result, a, b, c, x1, x2;
    cin >> a >> b >> c;
    cout << a << "x^2 " << b << "x " << c << "= 0";
    D = pow(b, 2) - 4 * a * c;
    cout << "D = " << D << endl;

    if (D > 0)
    {
        x1 = -b + sqrt(D) / (2 * a);
        x2 = -b - sqrt(D) / (2 * a);
        cout << "найденны корни \n" << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    else if (D == 0)
    {
        x1 = -b / (2 * a);
    }

    else
    {
        cout << "нет дейстаительных корней";
    }

    return 0;
}

int crammers_rule()
{
    float a11, a12, a13, a21, a22, a23, b1, b2, b3, determinant, result_x, result_y, x, y; // Поработать над типами данных переменных (с памятью)
    /* double:      float:
     * 112 байт      56 байт
     * 896 бит       448 бит
     */
    short int choose;
    cout << "Выберите количество уравнений в методе Краммера:";
    cin >> choose;
    switch (choose)
    {
    case 2:
        cout << "Введите два уравнение:" << endl;
        cout << " Введите коэффиценты: ";
        cin >> a11 >> a12;
        cin >> a21 >> a22;
        cout << " после =: ";
        cin >> b1 >> b2;
        cout << "\n";

        cout << a11 << " x1 + " << a12 << " x2 = " << b1 << endl;
        cout << a21 << " x1 + " << a22 << " x2 = " << b2 << "\n" << endl;

        cout << "Матрица определителя:" << endl;
        cout << a11 << " " << a12 << endl;
        cout << a21 << " " << a22 << endl;
        determinant = (a11 * a22) - (a12 * a21);
        cout << endl;

        cout << "Определитель = " << determinant << endl;

        cout << "Матрица для вычисления определителя x: " << endl;
        cout << b1 << " " << a12 << endl;
        cout << b2 << " " << a22 << endl;
        result_x = (b1 * a22) - (a12 * b2);
        cout << endl;

        cout << "Определитель х = " << result_x << endl;
        cout << endl;

        cout << "Матрица для вычисления определителя y: " << endl;
        cout << a11 << " " << b1 << endl;
        cout << a21 << " " << b2 << endl;
        result_y = (a11 * b2) - (b1 * a21);
        cout << endl;

        cout << "Определитель y = " << result_y << endl;
        cout << endl;
        x = result_x / determinant;
        cout << "x = " << x << endl;
        y = result_y / determinant;
        cout << "y = " << y << endl;
        break;
        //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    case 3:
        cout << "Введите три уравнение" << endl;
        cout << " Введите коэффиценты: ";
        cin >> a11 >> a12 >> a13;
        cin >> a21 >> a22 >> a23;
        cout << " после =: ";
        cin >> b1 >> b2 >> b3;
        cout << "\n";

        cout << a11 << "x1 + " << a12 << "x2 = " << b1 << endl;
        cout << a21 << "x1 + " << a22 << "x2 = " << b2 << endl;
        cout << a11 << "x1 + " << a12 << "x2 = " << b3 << endl;

        cout << "Матрица определителя " << endl;
        cout << a11 << " " << a12 << endl;
        cout << a21 << " " << a22 << endl;
        determinant = (a11 * a22) - (a12 * a21);

        cout << "Определитель = " << determinant << endl;

        cout << "Матрица для вычисления определителя x: " << endl;
        cout << b1 << " " << a12 << endl;
        cout << b2 << " " << a22 << endl;
        result_x = (b1 * a22) - (a12 * b2);

        cout << "Определитель х = " << result_x << endl;

        cout << "Матрица для вычисления определителя y: " << endl;
        cout << a11 << " " << b1 << endl;
        cout << a21 << " " << b2 << endl;
        result_y = (a11 * b2) - (b1 * a21);

        cout << "Определитель y = " << result_y << endl;
        x = result_x / determinant;
        cout << "x = " << x << endl;
        y = result_y / determinant;
        cout << "y = " << y << endl;
        break;
        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    default:
        cout << "Неправильные значения";
    }
    return 0;
}

int fraction()
{
    cout<<"Введите своё биквадратное уравнение:" << endl;
    return 0;
}

int trigonometry()
{
    cout<<"Введите своё тригонометрическое уравнение:" << endl;
    return 0;
}

int demonstration()
{
    cout<<"Введите своё показательное уравнение:" << endl;
    return 0;
}

int logarithmic()
{
    cout<<"Введите своё логарифмическое уравнение:" << endl;
    return 0;
}




/*
Задачи:

*/

