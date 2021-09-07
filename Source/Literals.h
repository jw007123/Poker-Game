#pragma once

namespace SDF
{
	typedef double f64;
	typedef float f32;
	typedef int i16;
	typedef long int i32;
	typedef unsigned char u8;
	typedef unsigned short u16;
	typedef long unsigned int u32;
	typedef size_t usize;

	constexpr f64 PI = 3.14159265359;
	constexpr usize PATH_MAX = 1024;
	constexpr f32 EPSILON_F32 = 0.000001f;
}