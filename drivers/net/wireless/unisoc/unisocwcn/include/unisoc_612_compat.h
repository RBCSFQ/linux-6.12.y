/* SPDX-License-Identifier: GPL-2.0 */
/*
 * 6.12 kernel API compatibility shims for UWE5621DS drivers
 */
#ifndef _UNISOC_612_COMPAT_H
#define _UNISOC_612_COMPAT_H

#include <linux/version.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/firmware.h>
#include <linux/rtnetlink.h>

/* filp_open() removed in 6.12 */
static inline struct file *compat_filp_open(const char *path, int flags, umode_t mode)
{
	return ERR_PTR(-ENOENT);
}
#define filp_open(path, flags, mode) compat_filp_open(path, flags, mode)

/* strcpy() no longer exported; use strscpy() */
#ifndef strcpy
#define strcpy(dst, src) strscpy(dst, src, sizeof(dst))
#endif

#endif
