//
// semver.h
//
// Copyright (c) 2015 Tomas Aparicio
// MIT licensed
//

#ifndef __SEMVER_H
#define __SEMVER_H
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * semver_t struct
 */

typedef struct semver_version_s {
  int major;
  int minor;
  int patch;
  char * metadata;
  char * prerelease;
} semver_t;

struct metadata_s {
  char * stage;
  int version[50];
  int version_count;
};

/**
 * Set prototypes
 */

int
semver_satisfies (semver_t x, semver_t y, const char * operator);

int
semver_compare (semver_t x, semver_t y);

int
semver_compare_meta (struct metadata_s xm, struct metadata_s ym);

int
semver_gt (semver_t x, semver_t y);

int
semver_gte (semver_t x, semver_t y);

int
semver_lt (semver_t x, semver_t y);

int
semver_lte (semver_t x, semver_t y);

int
semver_eq (semver_t x, semver_t y);

int
semver_neq (semver_t x, semver_t y);

void
semver_render (semver_t *x, char * dest);

int
semver_parse (const char *str, semver_t *ver);

void
semver_bump (semver_t *x);

void
semver_bump_minor (semver_t *x);

void
semver_bump_patch (semver_t *x);

void
semver_free (semver_t *x);

int
semver_is_valid (const char *s);
