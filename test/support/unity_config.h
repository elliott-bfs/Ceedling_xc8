#ifndef UNITY_CONFIG_H
#define UNITY_CONFIG_H

#define UNITY_EXCLUDE_SETJMP_H
#define UNITY_EXCLUDE_MATH_H
#define UNITY_EXCLUDE_FLOAT
#define UNITY_OUTPUT_START simulatorStart
#define UNITY_OUTPUT_COMPLETE simulatorQuit

#ifdef INTELLISENSE
#define TEST_FILE(...)
#define TEST_CASE(...)
#define TEST_RANGE(...)
#endif

void simulatorStart(void);
void simulatorQuit(void);

#endif // UNITY_CONFIG_H
 