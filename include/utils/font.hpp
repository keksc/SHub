#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

namespace font {
	FT_Library library;
	FT_Face face;
	FT_Error error;
	void init() {
		FT_Library library;
		error = FT_Init_FreeType(&library);
		if (error)
		{
			std::cout << "freetype: init err" << std::endl;
			return;
		}
		FT_Face face;
		error = FT_New_Face(library,
			"C:\\Windows\\Fonts\\arial.ttf",
			0,
			&face);
		if (error == FT_Err_Unknown_File_Format)
		{
			std::cout << "freetype: unknown file format" << std::endl;
		}
		else if (error)
		{
			std::cout << "freetype: error while loading font" << std::endl;
		}
		error = FT_Set_Pixel_Sizes(
			face,
			0,
			16);
	}

	void test() {
		error = FT_Load_Char(face, 'a', FT_LOAD_DEFAULT);
		if (error)
		{
			std::cout << "freetype: Failed to load Glyph: " << error << std::endl;
		}
	}

	void done() {
		FT_Done_Face(face);
		FT_Done_FreeType(library);
	}
}