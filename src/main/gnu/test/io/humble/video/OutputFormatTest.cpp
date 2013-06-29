/*
 * Copyright (c) 2013-Forward, Andrew "Art" Clarke
 *
 * This file is part of Humble Video.
 * 
 * Humble Video is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Humble Video is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with Humble Video.  If not, see <http://www.gnu.org/licenses/>.
 *
 * OutputFormatTest.cpp
 *
 *  Created on: Jun 28, 2013
 *      Author: aclarke
 */

#include <cstdlib>
#include <cstring>

#include "OutputFormatTest.h"
#include <io/humble/ferry/Logger.h>
#include <io/humble/ferry/RefPointer.h>
#include <io/humble/video/OutputFormat.h>

using namespace io::humble::ferry;
using namespace io::humble::video;

VS_LOG_SETUP(VS_CPP_PACKAGE);

OutputFormatTest::OutputFormatTest()
{
}

OutputFormatTest::~OutputFormatTest()
{
}

void
OutputFormatTest::setUp()
{

}

void
OutputFormatTest::tearDown() {

}
void
OutputFormatTest::testCreateOutputFormat() {
  RefPointer<OutputFormat> format;
  format = OutputFormat::guessFormat("flv", 0, 0);
  VS_LOG_DEBUG("Pointer: %p", format.value());
  VS_LOG_DEBUG("Name: %s", format->getName());
  VS_LOG_DEBUG("Long Name: %s", format->getLongName());
  VS_LOG_DEBUG("Extensions: %s", format->getExtensions());
  VS_LOG_DEBUG("MimeType: %s", format->getMimeType());
  int32_t n = format->getNumSupportedCodecs();
  VS_LOG_DEBUG("# Supported Codecs: %d", n);
  for(int32_t i = 0; i < n; i++) {
    VS_LOG_DEBUG("ID: %d, Tag: %d",
        format->getSupportedCodecId(i),
        format->getSupportedCodecTag(i));
  }
  VS_TUT_ENSURE("", strcmp("flv", format->getName()) == 0);
  format = OutputFormat::guessFormat(0, "foo.flv", 0);
  VS_TUT_ENSURE("", strcmp("flv", format->getName()) == 0);
  format = OutputFormat::guessFormat(0, 0, "video/x-flv");
  VS_TUT_ENSURE("", strcmp("flv", format->getName()) == 0);
}