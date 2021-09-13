#pragma once

#ifndef MATHF_H
#define MATHF_H

namespace HRPC_LIBS
{
    namespace Mathf
    {
        class Manager
        {
            Manager() {}
            Manager(const Manager &) = delete;
            Manager &operator=(const Manager &) = delete;

        public:
            const double Deg2Rad = PI / 180.0f;
            const double Rad2Deg = 180.0f / PI;

            ~Manager()
            {
            }

            static Manager &get()
            {
                static Manager m;
                return m;
            }

            float Lerp(float a, float b, float t)
            {
                t = constrain(t, 0.0f, 1.0f);
                return (a * (1 - t) + b * t);
            }

            float LerpUnclamped(float a, float b, float t)
            {
                return (a * (1 - t) + b * t);
            }

            float InverseLerp(float a, float b, float val)
            {
                val = constrain(val, a, b);
                if (a != b)
                    return ((val - a) / abs(a - b));
                else
                    return 0;
            }

            int Round(float f)
            {
                return (int)(f + 0.5);
            }

            float Sign(float f)
            {
                if (f < 0.0f)
                    return -1.0f;
                else
                    return 1.0f;
            }

            int Ceil(float f)
            {
                return (int)(f < 0.0 ? f : f + 0.9999);
            }

            int Floor(float f)
            {
                return (int)(f > 0.0 ? f : f - 0.9999);
            }

            float DeltaAngle(float current, float target)
            {
                current -= 360.0f * ((int)(current / 360.0));
                target -= 360.0f * ((int)(target / 360.0));

                if (abs(target - current) > 180)
                    return target - current - Sign(target - current) * 360.0;
                else
                    return target - current;
            }

            template <typename First>
            float Max(First first)
            {
                return first;
            }
            template <typename First, typename... Rest>
            float Max(First first, Rest... rest)
            {
                if (first > Max(rest...))
                    return first;
                else
                    return Max(rest...);
            }

            template <typename First>
            float Min(First first)
            {
                return first;
            }
            template <typename First, typename... Rest>
            float Min(First first, Rest... rest)
            {
                if (first < Min(rest...))
                    return first;
                else
                    return Min(rest...);
            }

            bool Approximately(float a, float b, double err_percent)
            {
                if (abs(a - b) < (abs(a) + abs(b)) * err_percent * 0.005)
                    return true;
                else
                    return false;
            }

            bool IsPowerOfTwo(unsigned long x)
            {
                return (x != 0) && ((x & (x - 1)) == 0);
            }

            template <typename Value>
            String ToString(Value value, uint8_t digits, uint8_t decimalDigits)
            {
                char c[digits + decimalDigits + 1];
                dtostrf(value, digits + decimalDigits + 1, decimalDigits, c);
                return String(c);
            }
        }; // Manager
    }      // Mathf
} // HRPC_LIBS

#define Mathf HRPC_LIBS::Mathf::Manager::get()

#endif