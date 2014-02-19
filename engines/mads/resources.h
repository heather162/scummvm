/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
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
 */

#ifndef MADS_RESOURCES_H
#define MADS_RESOURCES_H

#include "common/scummsys.h"
#include "common/stream.h"
#include "common/str.h"

namespace MADS {

class MADSEngine;

class ResourcesManager {
private:
	MADSEngine *_vm;
public:
	ResourcesManager(MADSEngine *vm);

	/**
	 * Return a named resource
	 */
	Common::SeekableReadStream *get(const Common::String &resourceName, bool loadFlag = false) {
		// TODO
		return nullptr;
	}

	Common::SeekableReadStream *openFile(const Common::String &resourceName) { 
		return get(resourceName, false); 
	}

	/**
	 * Release a previously loaded resource
	 */
	void toss(const Common::String &resourceName) {
		// TODO
	}
};

} // End of namespace MADS

#endif /* MADS_RESOURCES_H */
