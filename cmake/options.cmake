option(
  SNAKE_WARNINGS_AS_ERRORS
  "True to treat warnings as errors"
  false)

option(
  SNAKE_USE_SANITIZERS
  "Enable sanitizers for supported targets"
  OFF)

# Individual sanitizer options
option(
  SNAKE_SANITIZER_ADDRESS
  "Enable AddressSanitizer"
  ON)
option(
  SNAKE_SANITIZER_UNDEFINED
  "Enable UndefinedBehaviorSanitizer"
  ON)
option(
  SNAKE_SANITIZER_LEAK
  "Enable LeakSanitizer"
  ON)
option(
  SNAKE_SANITIZER_THREAD
  "Enable ThreadSanitizer"
  OFF)
option(
  SNAKE_SANITIZER_MEMORY
  "Enable MemorySanitizer"
  OFF)
option(
  SNAKE_SANITIZER_SAFE_STACK
  "Enable SafeStackSanitizer"
  OFF)
option(
  SNAKE_SANITIZER_INTEGER
  "Enable IntegerSanitizer"
  OFF)
