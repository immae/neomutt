/**
 * @file
 * Type representing a path
 *
 * @authors
 * Copyright (C) 2020 Richard Russon <rich@flatcap.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MUTT_CONFIG_PATH_H
#define MUTT_CONFIG_PATH_H

#include <stdint.h>

struct ConfigSet;

typedef uint8_t MuttPathFlags;   ///< Flags for MuttPath, e.g. #MPATH_RESOLVED
#define MPATH_NO_FLAGS        0  ///< No flags are set
#define MPATH_RESOLVED  (1 << 0) ///< Path has been resolved, see mx_path_resolve()
#define MPATH_TIDY      (1 << 1) ///< Path has been tidied, see MxOps::path_tidy()
#define MPATH_CANONICAL (1 << 2) ///< Path is canonical, see MxOps::path_canon()
#define MPATH_ROOT      (1 << 3) ///< Path is at the root of an Account (it has no parent)

/**
 * MuttPath - A path to a Mailbox, file or directory
 */
struct MuttPath
{
  char *orig;          ///< User-entered path
  char *canon;         ///< Canonical path
  int type;            ///< Path type, enum MailboxType
  MuttPathFlags flags; ///< Flags describing what's known about the path
};

void path_init(struct ConfigSet *cs);

#endif /* MUTT_CONFIG_PATH_H */
