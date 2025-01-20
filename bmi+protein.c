#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Helper function to convert a string to lowercase
void to_lowercase(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = tolower(s[i]);
    }
}

int main(void)
{
    // Get input for weight and height
    float weight = get_float("Enter weight in kg: ");
    float height = get_float("Enter height in meters: ");

    // Calculate BMI
    float bmi = weight / (height * height);
    printf("Your BMI is: %.1f\n", bmi);

    // Classify BMI
    if (bmi < 18.5)
    {
        printf("Underweight\n");
    }
    else if (bmi >= 18.5 && bmi <= 24.9)
    {
        printf("Normal\n");
    }
    else
    {
        printf("Overweight\n");
    }

    // Ask about essential protein intake
    string protein_qs = get_string("Would you like to find out your essential protein intake per day? yes/no ");
    to_lowercase(protein_qs);

    if (strcmp(protein_qs, "yes") == 0)
    {
        float protein_intake = 0.8 * weight;
        printf("Daily protein intake: %.1f grams\n", protein_intake);
    }
    else if (strcmp(protein_qs, "no") == 0)
    {
        printf("OK\n");
    }
    else
    {
        printf("Invalid input, please enter either yes or no.\n");
    }

    // Ask about protein intake for losing fat and building muscle
    string protein_2 = get_string("Would you like to find out the amount of protein needed to lose fat & build muscle? yes/no ");
    to_lowercase(protein_2);

    if (strcmp(protein_2, "yes") == 0)
    {
        float protein_lfm = 1.8 * weight;
        printf("Daily protein intake to lose fat & build muscle: %.1f grams\n", protein_lfm);
    }
    else if (strcmp(protein_2, "no") == 0)
    {
        printf("OK\n");
    }
    else
    {
        printf("Invalid input, please enter either yes or no.\n");
    }

    // Ask about protein intake for losing or gaining weight
    string protein_3 = get_string("Would you like to find out how much daily protein is needed to lose or gain weight? lose/gain ");
    to_lowercase(protein_3);

    if (strcmp(protein_3, "lose") == 0)
    {
        float protein_lw = 1.2 * weight;
        printf("Daily protein intake to lose weight: %.1f grams\n", protein_lw);
    }
    else if (strcmp(protein_3, "gain") == 0)
    {
        float protein_gw = 1.8 * weight;
        printf("Daily protein intake to gain weight: %.1f grams\n", protein_gw);
    }
    else
    {
        printf("Invalid input, please enter either lose or gain.\n");
    }

    return 0;
}
