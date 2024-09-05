#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define DA_DECLARE(type)                           \
  DA_TYPE(type)                                    \
  type##_da type##_da_init(void);                  \
  bool type##_da_push(type##_da* arr, type* elem); \
  bool type##_da_pop(type##_da* arr, type* elem);  \
  void type##_da_free(type##_da* arr);

#define DA_DEFINE(type) \
  DA_INIT(type)         \
  DA_PUSH(type)         \
  DA_POP(type)          \
  DA_FREE(type)

#define DA_TYPE(type) \
  typedef struct {    \
    type* array;      \
    size_t length;    \
    size_t capacity;  \
  } type##_da;

#define DA_INIT(type)              \
  type##_da type##_da_init(void) { \
    type##_da arr = {0};           \
    return arr;                    \
  }

#define DA_PUSH(type)                                                 \
  bool type##_da_push(type##_da* arr, type* elem) {                   \
    if (!arr || !elem) return false;                                  \
    if (arr->length >= arr->capacity) {                               \
      arr->capacity = arr->capacity ? arr->capacity * 2 : 1;          \
      arr->array = realloc(arr->array, sizeof(type) * arr->capacity); \
      if (!arr->array) return false;                                  \
    }                                                                 \
    arr->array[arr->length++] = *elem;                                \
    return true;                                                      \
  }

#define DA_POP(type)                                                  \
  bool type##_da_pop(type##_da* arr, type* elem) {                    \
    if (!arr || !arr->length) return false;                           \
    *elem = arr->array[--arr->length];                                \
    if (arr->length <= arr->capacity / 2) {                           \
      arr->capacity /= 2;                                             \
      arr->array = realloc(arr->array, sizeof(type) * arr->capacity); \
      if (!arr->array) return false;                                  \
    }                                                                 \
    return true;                                                      \
  }

#define DA_FREE(type)                   \
  void type##_da_free(type##_da* arr) { \
    if (!arr) return;                   \
    free(arr->array);                   \
    arr->array = NULL;                  \
    arr->capacity = 0;                  \
    arr->length = 0;                    \
  }

#endif  // !DYNAMIC_ARRAY_H
