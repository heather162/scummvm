/* Copyright (C) 1994-1998 Revolution Software Ltd.
 * Copyright (C) 2003-2005 The ScummVM project
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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$
 */

#ifndef DRIVER96_H
#define DRIVER96_H

namespace Sword2 {

class Sword2Engine;

// Error codes

enum {
	// Generic error codes

	RD_OK,
	RDERR_UNKNOWN,
	RDERR_INVALIDPOINTER,
	RDERR_OUTOFMEMORY,
	RDERR_INVALIDFILENAME,

	// Drawing error codes

	RDERR_DECOMPRESSION,

	// Language and version error codes

	RDERR_OPENVERSIONFILE,

	// Sprite drawing error codes

	RDERR_NOTIMPLEMENTED,
	RDERR_UNKNOWNTYPE,
	RDERR_INVALIDSCALING,
	RDERR_NOTCLOSED,
	RDERR_NOTOPEN,

	// Menubar error codes

	RDERR_INVALIDMENU,
	RDERR_INVALIDPOCKET,
	RDERR_INVALIDCOMMAND,

	// Palette fading error codes

	RDERR_FADEINCOMPLETE,

	// Sound engine error codes

	RDERR_SPEECHPLAYING,
	RDERR_SPEECHNOTPLAYING,
	RDERR_INVALIDWAV,
	RDERR_FXALREADYOPEN,
	RDERR_NOFREEBUFFERS,
	RDERR_FXNOTOPEN,
	RDERR_FXFUCKED,
	RDERR_INVALIDID
};

// Sprite defines

enum {
	// This is the low byte part of the sprite type.

	RDSPR_TRANS			= 0x0001,
	RDSPR_BLEND			= 0x0004,
	RDSPR_FLIP			= 0x0008,
	RDSPR_SHADOW			= 0x0010,
	RDSPR_DISPLAYALIGN		= 0x0020,
	RDSPR_NOCOMPRESSION		= 0x0040,
	RDSPR_EDGEBLEND			= 0x0080,	// Unused

	// This is the high byte part of the sprite type, which defines what
	// type of compression is used. Unless RDSPR_NOCOMPRESSION is set.

	RDSPR_RLE16			= 0x0000,
	RDSPR_RLE256			= 0x0100,
	RDSPR_RLE256FAST		= 0x0200
};

// Fading defines

enum {
	RDFADE_NONE,
	RDFADE_UP,
	RDFADE_DOWN,
	RDFADE_BLACK
};

// Mouse defines

enum {
	RDMOUSE_NOFLASH,
	RDMOUSE_FLASH
};

// Menubar defines.

#define RDMENU_TOP			0
#define RDMENU_BOTTOM			1

enum {
	RDMENU_HIDDEN,
	RDMENU_SHOWN,
	RDMENU_OPENING,
	RDMENU_CLOSING,
	RDMENU_ALMOST_HIDDEN
};

#define RDMENU_ICONWIDE			35
#define RDMENU_ICONDEEP			30
#define RDMENU_ICONSTART		24
#define RDMENU_ICONSPACING		5
#define RDMENU_MAXPOCKETS		15
#define RDMENU_MENUDEEP			40

// Sound defines

enum {
	RDSE_SAMPLEFINISHED		= 0,
	RDSE_SAMPLEPLAYING		= 1,
	RDSE_FXTOCLEAR			= 0,		// Unused
	RDSE_FXCACHED			= 1,		// Unused
	RDSE_FXSPOT			= 0,
	RDSE_FXLOOP			= 1,
	RDSE_FXLEADIN			= 2,
	RDSE_FXLEADOUT			= 3,
	RDSE_QUIET			= 1,
	RDSE_SPEAKING			= 0
};

// Palette defines

enum {
	RDPAL_FADE,
	RDPAL_INSTANT
};

// Blitting FX defines

enum {
	RDBLTFX_SPRITEBLEND		= 0x01,
	RDBLTFX_SHADOWBLEND		= 0x02,
	RDBLTFX_EDGEBLEND		= 0x04
};

// Structure definitions

#if !defined(__GNUC__)
	#pragma START_PACK_STRUCTS
#endif

struct Parallax {
	uint16 w;
	uint16 h;
	uint32 offset[2];	// 2 is arbitrary
} GCC_PACK;

#if !defined(__GNUC__)
	#pragma END_PACK_STRUCTS
#endif

} // End of namespace Sword2

#endif
