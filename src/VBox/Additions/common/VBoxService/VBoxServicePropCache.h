/* $Id: */
/** @file
 * VBoxServicePropCache - Guest property cache.
 */

/*
 * Copyright (C) 2010 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef ___VBoxServicePropCache_h
#define ___VBoxServicePropCache_h

#include "VBoxServiceInternal.h"

# ifdef VBOX_WITH_GUEST_PROPS

/** Indicates wheter a guest property is temporary and either should
 *  - a) get a "reset" value assigned (via VBoxServicePropCacheUpdateEntry)
 *       as soon as the property cache gets destroyed, or
 *  - b) get deleted when no reset value is specified.
 */
#define VBOXSERVICEPROPCACHEFLAG_TEMPORARY              RT_BIT(1)
/** Indicates whether a property every time needs to be updated, regardless
 *  if its real value changed or not. */
#define VBOXSERVICEPROPCACHEFLAG_ALWAYS_UPDATE          RT_BIT(2)
/** The guest property gets deleted when
 *  - a) the property cache gets destroyed, or
 *  - b) the VM gets reset / shutdown / destroyed.
 */
#define VBOXSERVICEPROPCACHEFLAG_TRANSIENT              RT_BIT(3)

int VBoxServicePropCacheCreate(PVBOXSERVICEVEPROPCACHE pCache, uint32_t uClientId);
int VBoxServicePropCacheUpdateEntry(PVBOXSERVICEVEPROPCACHE pCache, const char *pszName, uint32_t fFlags, const char *pszValueReset);
int VBoxServicePropCacheUpdate(PVBOXSERVICEVEPROPCACHE pCache, const char *pszName, const char *pszValueFormat, ...);
int VBoxServicePropCacheUpdateByPath(PVBOXSERVICEVEPROPCACHE pCache, const char *pszValue, uint32_t fFlags, const char *pszPathFormat, ...);
int VBoxServicePropCacheFlush(PVBOXSERVICEVEPROPCACHE pCache);
void VBoxServicePropCacheDestroy(PVBOXSERVICEVEPROPCACHE pCache);
# endif /* VBOX_WITH_GUEST_PROPS */

#endif  /* ___VBoxServicePropCache_h */

