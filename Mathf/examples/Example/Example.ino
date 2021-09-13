#include <Mathf.h>

void setup()
{
    Serial.begin(9600);
    while (!Serial);

    const int a = 12;
    const float b = 7.5;
    const long c = 3;

    const int A = 45;
    const int B = 180;
    const int C = -225;
    const int D = 450;

    /* Lerp() */
    Serial.println(Mathf.Lerp(c, a, 0.0)); // Result : 3
    Serial.println(Mathf.Lerp(c, a, 0.5)); // Result : 7.5
    Serial.println(Mathf.Lerp(c, a, 1.0)); // Result : 12
    Serial.println(Mathf.Lerp(c, a, 1.5)); // Result : 12
    Serial.println();

    /* LerpUnclamped() */
    Serial.println(Mathf.LerpUnclamped(c, a, 1.5)); // Result : 16.5
    Serial.println();

    /* InverseLerp() */
    Serial.println(Mathf.InverseLerp(c, a, b)); // Result : 0.5
    Serial.println();

    /* Round() */
    Serial.println(Mathf.Round(b)); // Result : 8
    Serial.println();

    /* Sign() */
    Serial.println(Mathf.Sign(a));  // Result : 1.0
    Serial.println(Mathf.Sign(-b)); // Result : -1.0
    Serial.println();

    /* Ceil() */
    Serial.println(Mathf.Ceil(b)); // Result : 8
    Serial.println();

    /* Floor() */
    Serial.println(Mathf.Floor(b)); // Result : 7
    Serial.println();

    /* DeltaAngle() */
    Serial.println(Mathf.DeltaAngle(A, C)); // Result : 90
    Serial.println(Mathf.DeltaAngle(B, D)); // Result : -90
    Serial.println();

    /* Max() and Min() */
    Serial.println(Mathf.Max(a, b, c)); // Result : 12
    Serial.println(Mathf.Max(b, c));    // Result : 7.5
    Serial.println(Mathf.Min(a, b, c)); // Result : 3
    Serial.println(Mathf.Min(a, b));    // Result : 7.5
    Serial.println();

    /* Approximately() */
    Serial.println(Mathf.Approximately(1.00, 1.04, 3)); // Result : 0, threshold = 1.02×3% = 0.0306
    Serial.println(Mathf.Approximately(1.00, 1.04, 4)); // Result : 1, threshold = 1.02×4% = 0.0408
    Serial.println();

    /* IsPowerOfTwo() */
    Serial.println(Mathf.IsPowerOfTwo(8)); // Result : 1
    Serial.println(Mathf.IsPowerOfTwo(3)); // Result : 0
    Serial.println();

    /* ToString() */
    Serial.println(Mathf.ToString(123.4567, 3, 4)); // Result 123.4567
    Serial.println(Mathf.ToString(123.4567, 3, 2)); // Result 123.46
    Serial.println(Mathf.ToString(123.4567, 3, 6)); // Result 123.456700
}

void loop()
{
}