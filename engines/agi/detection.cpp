/* ScummVM - Scumm Interpreter
 * Copyright (C) 2006 The ScummVM project
 *
 * cinE Engine is (C) 2004-2005 by CinE Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $URL:$
 * $Id:$
 *
 */

#include "common/stdafx.h"

#include "base/plugins.h"

#include "common/advancedDetector.h"
#include "common/file.h"

#include "agi/agi.h"


namespace Agi {
static DetectedGameList GAME_detectGames(const FSList &fslist);
}

using Common::File;

static const PlainGameDescriptor agiGames[] = {
	{"kq1", "Kings Quest I" },

	{0, 0}
};

ADVANCED_DETECTOR_DEFINE_PLUGIN(AGI, Agi::AgiEngine, Agi::GAME_detectGames, agiGames, 0);

REGISTER_PLUGIN(AGI, "AGI v2 + v3 Engine", "Sierra AGI Engine (C) Sierra On-Line Software");


namespace Agi {

#define FILE_MD5_BYTES 5000

using Common::ADGameFileDescription;
using Common::ADGameDescription;

using Common::File;

static const ADGameFileDescription AGI_KQ1_PC_20F_GameFiles[] = {
	{ "logdir",		0,	"10ad66e2ecbd66951534a50aedcd0128"},
};
static const ADGameFileDescription AGI_KQ1_2GS_10S_GameFiles[] = {
	{ "logdir",		0,	"f4277aa34b43d37382bc424c81627617"},
};
static const ADGameFileDescription AGI_KQ1_MAC_20C_GameFiles[] = {
	{ "logdir",		0,	"d4c4739d4ac63f7dbd29255425077d48"},
};


static const AGIGameDescription gameDescriptions[] = {
	{
		// kings quest 1 : pc : 2.0F
		{
			"kq1",
			"",
			ARRAYSIZE(AGI_KQ1_PC_20F_GameFiles),
			AGI_KQ1_PC_20F_GameFiles,
			Common::EN_ANY,
			Common::kPlatformPC,
		},
		GType_V2,
		0,
		0x2917,
	},

	{
		// kings quest 1 : 2gs : 1.0S
		{
			"kq1",
			"",
			ARRAYSIZE(AGI_KQ1_2GS_10S_GameFiles),
			AGI_KQ1_2GS_10S_GameFiles,
			Common::EN_ANY,
			Common::kPlatformApple2GS,
		},
		GType_V2,
		0,
		0x2272,
	},


	{
		// kings quest 1 : Mac : 2.0C
		{
			"kq1",
			"",
			ARRAYSIZE(AGI_KQ1_MAC_20C_GameFiles),
			AGI_KQ1_MAC_20C_GameFiles,
			Common::EN_ANY,
			Common::kPlatformMacintosh,
		},
		GType_V2,
		0,
		0x2440,
	},


};

bool AgiEngine::initGame() {
	int i = Common::real_ADVANCED_DETECTOR_DETECT_INIT_GAME(
		(const byte *)gameDescriptions,
		sizeof(AGIGameDescription),
		ARRAYSIZE(gameDescriptions),
		FILE_MD5_BYTES,
		agiGames
		);
	_gameDescription = &gameDescriptions[i];
	return true;
}

DetectedGameList GAME_detectGames(const FSList &fslist) {
	return real_ADVANCED_DETECTOR_DETECT_GAMES_FUNCTION(
		fslist,
		(const byte *)gameDescriptions,
		sizeof(AGIGameDescription),
		ARRAYSIZE(gameDescriptions),
		FILE_MD5_BYTES,
		agiGames
	);
}

} // End of namespace Agi

