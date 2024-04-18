/**
 * @file crypto_config.h
 * @brief CycloneCRYPTO configuration file
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2021 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneCRYPTO Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.3.0
 **/

#ifndef _CRYPTO_CONFIG_H
#define _CRYPTO_CONFIG_H

// Desired trace level (for debugging purposes)
// #define CRYPTO_TRACE_LEVEL TRACE_LEVEL_INFO

#define ESP32_CRYPTO_CIPHER_SUPPORT ENABLED
#define ESP32_CRYPTO_TRNG_SUPPORT DISABLED
#define ESP32_CRYPTO_HASH_SUPPORT DISABLED
#define ESP32_CRYPTO_RSA_SUPPORT DISABLED

// Multiple precision integer support
#define MPI_SUPPORT ENABLED
// Assembly optimizations for time-critical routines
#define MPI_ASM_SUPPORT DISABLED 
//DES support
#define DES_SUPPORT ENABLED
//Triple DES support
#define DES3_SUPPORT ENABLED
//AES support
#define AES_SUPPORT ENABLED
//Blowfish support
#define BLOWFISH_SUPPORT ENABLED
//Twofish support
#define TWOFISH_SUPPORT ENABLED
//Serpent support
#define SERPENT_SUPPORT ENABLED
//XTEA support
#define XTEA_SUPPORT ENABLED

//ECB mode support
#define ECB_SUPPORT ENABLED
//CBC mode support
#define CBC_SUPPORT ENABLED

#endif