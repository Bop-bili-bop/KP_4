#ifndef VALIDATION_H
#define VALIDATION_H
double val_double_input(const char *prompt)
{
    double value = 0 ;
    int input = 0;
    do
    {
        printf("%s", prompt);
        input = scanf("%lf", &value);
        if (input != 1)
        {
            printf("Invalid input. Please enter a valid number.\n");
            value = 0;
        }
        fflush(stdin);
    }
    while (input != 1);
    return value;
}
double val_char_input(const char *prompt)
{
    char value = 0 ;
    char input = 0;
    do
    {
        printf("%s", prompt);
        input = scanf("%c", &value);
        if (input != 1)
        {
            printf("Invalid input. Please enter a valid number.\n");
            value = 0;
        }
        fflush(stdin);
    }
    while (input != 1);
    return value;
}
double val_dx(const char *prompt, const int *condition)
{

}
#endif //VALIDATION_H
