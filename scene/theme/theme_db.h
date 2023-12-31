/**************************************************************************/
/*  theme_db.h                                                            */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef THEME_DB_H
#define THEME_DB_H

#include "core/object/class_db.h"
#include "core/object/ref_counted.h"

class Font;
class StyleBox;
class Texture2D;
class Theme;

class ThemeDB : public Object {
	GDCLASS(ThemeDB, Object);

	static ThemeDB *singleton;

	// Universal Theme resources used when no other theme has the item.
	Ref<Theme> default_theme;
	Ref<Theme> project_theme;

	// Universal default values, final fallback for every theme.
	float fallback_base_scale;
	Ref<Font> fallback_font;
	int fallback_font_size;
	Ref<Texture2D> fallback_icon;
	Ref<StyleBox> fallback_stylebox;

protected:
	static void _bind_methods();

public:
	void initialize_theme();
	void initialize_theme_noproject();
	void finalize_theme();

	// Universal Theme resources

	void set_default_theme(const Ref<Theme> &p_default);
	Ref<Theme> get_default_theme();

	void set_project_theme(const Ref<Theme> &p_project_default);
	Ref<Theme> get_project_theme();

	// Universal default values.

	void set_fallback_base_scale(float p_base_scale);
	float get_fallback_base_scale();

	void set_fallback_font(const Ref<Font> &p_font);
	Ref<Font> get_fallback_font();

	void set_fallback_font_size(int p_font_size);
	int get_fallback_font_size();

	void set_fallback_icon(const Ref<Texture2D> &p_icon);
	Ref<Texture2D> get_fallback_icon();

	void set_fallback_stylebox(const Ref<StyleBox> &p_stylebox);
	Ref<StyleBox> get_fallback_stylebox();

	static ThemeDB *get_singleton();
	ThemeDB();
	~ThemeDB();
};

#endif // THEME_DB_H
