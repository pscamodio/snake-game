# sanitizers.cmake Function to enable sanitizers for a target if
# SNAKE_USE_SANITIZERS is ON

function(target_configure_sanitizers target)
  if(NOT SNAKE_USE_SANITIZERS)
    return()
  endif()

  set(SANITIZERS)
  if(SNAKE_SANITIZER_ADDRESS)
    list(
      APPEND
      SANITIZERS
      "address")
  endif()
  if(SNAKE_SANITIZER_UNDEFINED)
    list(
      APPEND
      SANITIZERS
      "undefined")
  endif()
  if(SNAKE_SANITIZER_LEAK)
    list(
      APPEND
      SANITIZERS
      "leak")
  endif()
  if(SNAKE_SANITIZER_THREAD)
    list(
      APPEND
      SANITIZERS
      "thread")
  endif()
  if(SNAKE_SANITIZER_MEMORY)
    list(
      APPEND
      SANITIZERS
      "memory")
  endif()
  if(SNAKE_SANITIZER_SAFE_STACK)
    list(
      APPEND
      SANITIZERS
      "safe-stack")
  endif()
  if(SNAKE_SANITIZER_INTEGER)
    list(
      APPEND
      SANITIZERS
      "integer")
  endif()

  if(MSVC)
    # Only address sanitizer is supported
    if(SNAKE_SANITIZER_ADDRESS)
      target_compile_options(${target} PRIVATE /fsanitize=address)
      target_link_options(
        ${target}
        PRIVATE
        /INCREMENTAL:NO
        /fsanitize=address)
    endif()
  elseif(
    CMAKE_CXX_COMPILER_ID
    MATCHES
    "Clang")
    # Clang supports many sanitizers
    set(SUPPORTED
        "address"
        "undefined"
        "leak"
        "thread"
        "memory"
        "safe-stack"
        "integer")
    set(ENABLED)
    foreach(san ${SANITIZERS})
      list(
        FIND
        SUPPORTED
        ${san}
        idx)
      if(NOT
         idx
         EQUAL
         -1)
        list(
          APPEND
          ENABLED
          ${san})
      endif()
    endforeach()
    if(ENABLED)
      string(
        REPLACE ";"
                ","
                ENABLED_FLAGS
                "${ENABLED}")
      set(SANITIZER_FLAGS "-fsanitize=${ENABLED_FLAGS}")
      target_compile_options(${target} PRIVATE ${SANITIZER_FLAGS}
                                               -fno-omit-frame-pointer)
      target_link_options(
        ${target}
        PRIVATE
        ${SANITIZER_FLAGS})
    endif()
  elseif(
    CMAKE_CXX_COMPILER_ID
    MATCHES
    "GNU")
    # GCC supports address, undefined, thread
    set(SUPPORTED
        "address"
        "undefined"
        "thread")
    set(ENABLED)
    foreach(san ${SANITIZERS})
      list(
        FIND
        SUPPORTED
        ${san}
        idx)
      if(NOT
         idx
         EQUAL
         -1)
        list(
          APPEND
          ENABLED
          ${san})
      endif()
    endforeach()
    if(ENABLED)
      string(
        REPLACE ";"
                ","
                ENABLED_FLAGS
                "${ENABLED}")
      set(SANITIZER_FLAGS "-fsanitize=${ENABLED_FLAGS}")
      target_compile_options(${target} PRIVATE ${SANITIZER_FLAGS}
                                               -fno-omit-frame-pointer)
      target_link_options(
        ${target}
        PRIVATE
        ${SANITIZER_FLAGS})
    endif()
  endif()
endfunction()
