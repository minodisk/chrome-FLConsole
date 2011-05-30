/******************************************************************************
	�o�x�� -babel-
		�o�x�����W���[���w�b�_�t�@�C��
											Coded by Wraith	in July 14, 2002.
******************************************************************************/

//�@Tab�����S�����ɐݒ肵�ĕ\�������Ă��������B

///////////////////////////////////////////////////////////////////////////////
//
//	�� babel.h
//		http://tricklib.com/cxx/ex/babel/babel.h
//
//	�� �֘A�t�@�C��
//		�{���W���[���̖{��
//		http://tricklib.com/cxx/ex/babel/babel.cpp
//		�{���W���[���Ŏg�p����X�R�A�}�b�s���OCSV
//		http://tricklib.com/cxx/ex/babel/scoremap.csv
//		�{���W���[���Ŏg�p����CP932�}�b�s���OCSV
//		http://tricklib.com/cxx/ex/babel/cp932.csv
//		�{���W���[���Ŏg�p����UTC�}�b�s���OCSV
//		http://tricklib.com/cxx/ex/babel/utc.csv
//		�{���W���[���Ŏg�p����A�b�v���}�b�s���OCSV
//		http://tricklib.com/cxx/ex/babel/apple.csv
//		�{���W���[���Ŏg�p����SJIS-EUC�}�b�s���OCSV
//		http://tricklib.com/cxx/ex/babel/sjis-euc.csv
//		�{���W���[���Ŏg�p����EUC-UNICODE�}�b�s���OCSV
//		http://tricklib.com/cxx/ex/babel/euc-uni.csv
//		�{���W���[���Ŏg�p����CP932�}�b�s���O�f�[�^�t�@�C��
//		http://tricklib.com/cxx/ex/babel/c932-uni.dat
//		http://tricklib.com/cxx/ex/babel/uni-c932.dat
//		�{���W���[���Ŏg�p����UTC�}�b�s���O�f�[�^�t�@�C��
//		http://tricklib.com/cxx/ex/babel/utc-uni.dat
//		http://tricklib.com/cxx/ex/babel/uni-utc.dat
//		�{���W���[���Ŏg�p����SJIS-EUC�}�b�s���O�f�[�^�t�@�C��
//		http://tricklib.com/cxx/ex/babel/sjis-euc.dat
//		http://tricklib.com/cxx/ex/babel/euc-sjis.dat
//		�{���W���[���Ŏg�p����EUC-UNICODE�}�b�s���O�f�[�^�t�@�C��
//		http://tricklib.com/cxx/ex/babel/uni-euc.dat
//		http://tricklib.com/cxx/ex/babel/euc2-uni.dat
//		http://tricklib.com/cxx/ex/babel/euc3-uni.dat
//		�{���W���[���Ŏg�p����X�R�A�}�b�s���O�f�[�^�t�@�C��
//		http://tricklib.com/cxx/ex/babel/sjis-scr.dat
//		http://tricklib.com/cxx/ex/babel/euc-scr.dat
//		http://tricklib.com/cxx/ex/babel/uni-scr.dat
//		�S�t�@�C���p�b�N
//		http://tricklib.com/cxx/ex/babel/babel.lzh
//		http://tricklib.com/cxx/ex/babel/babel.zip
//
//	�� ���t�@�����X�E�T�|�[�g�y�[�W
//		http://tricklib.com/cxx/ex/babel/
//
//	�� ���C�Z���X���
//		http://tricklib.com/license.htm
//

#ifndef __BABEL_BABEL_H__

#define __BABEL_BABEL_H__

#if !defined(__WITH_BABEL__)
#	define	__WITH_BABEL__
#endif

#include <cassert>

#if defined(NDEBUG) && defined(_DEBUG)
#	define _DEBUG
#endif

namespace {
//	int unimplemented;
};

//
//	���R���p�C�����ɂ��e�펩������
//

	//	Borland ...
#	if defined(__BORLANDC__)
#		if !defined(__UNICODE_CHAR_SIZE_2__)
#			define __UNICODE_CHAR_SIZE_2__
#		endif
#		if !defined(__LITTLE_ENDIAN_COMPUTER__)
#			define __LITTLE_ENDIAN_COMPUTER__
#		endif
#		if !(defined(__USING_ANSI__) || defined(__USING_SJIS__) || defined(__USING_EUC__) || defined(__USING_UTF8__) || defined(__USING_UNKNOWN__))
#			define	__USING_SJIS__
#		endif
#	endif

	//	CodeWarrior ...
#	if defined(__MWERKS__)
#	endif

	//	Microsoft ...
#	if defined(_MSC_VER)
#		if !defined(__UNICODE_CHAR_SIZE_2__)
#			define __UNICODE_CHAR_SIZE_2__
#		endif
#		if !defined(__LITTLE_ENDIAN_COMPUTER__)
#			define __LITTLE_ENDIAN_COMPUTER__
#		endif
#		if !(defined(__USING_ANSI__) || defined(__USING_SJIS__) || defined(__USING_EUC__) || defined(__USING_UTF8__) || defined(__USING_UNKNOWN__))
#			define	__USING_SJIS__
#		endif
#	endif

	//	gcc/g++ ...
#	if defined(__GNUC__)
#	endif


//
//	���x�[�X�G���R�[�f�B���O�w��}�N��
//

//	�R���p�C�����Ɏw�肷��̂��ʓ|�ȏꍇ�͈ȉ��̃R�����g�s����K�؂Ȏw���
//	(�R�����g����������)�L��ɂ��Ă��������B���������w�肪�Ȃ���Ȃ��ꍇ��
//	���������ʂ���܂����A���m�ɔ��f����Ȃ������蔻�ʂׂ̈�(�]��)�R�[�h��
//	�������ꂽ�肷��\��������܂��B
//
//#define __UNICODE_CHAR_SIZE_2__
//#define __UNICODE_CHAR_SIZE_4__

#	if !(defined(__UNICODE_CHAR_SIZE_2__) || defined(__UNICODE_CHAR_SIZE_4__))
#		define	__UNICODE_CHAR_SIZE_UNKNOWN__
#	endif


//
//	���G���f�B�A���w��}�N��
//

//	�R���p�C�����Ɏw�肷��̂��ʓ|�ȏꍇ�͈ȉ��̃R�����g�s����K�؂Ȏw���
//	(�R�����g����������)�L��ɂ��Ă��������B���������w�肪�Ȃ���Ȃ��ꍇ��
//	���������ʂ���܂����A���m�ɔ��f����Ȃ������蔻�ʂׂ̈�(�]��)�R�[�h��
//	�������ꂽ�肷��\��������܂��B
//
//#define __LITTLE_ENDIAN_COMPUTER__
//#define __BIG_ENDIAN_COMPUTER__

#	if !(defined(__LITTLE_ENDIAN_COMPUTER__) || defined(__BIG_ENDIAN_COMPUTER__))
#		define	__UNKNOWN_ENDIAN_COMPUTER__
#	endif


//
//	���x�[�X�G���R�[�f�B���O�w��}�N��
//

//	�R���p�C�����Ɏw�肷��̂��ʓ|�ȏꍇ�͈ȉ��̃R�����g�s����K�؂Ȏw���
//	(�R�����g����������)�L��ɂ��Ă��������B���������w�肪�Ȃ���Ȃ��ꍇ��
//	���������ʂ���܂����A���m�ɔ��f����Ȃ������蔻�ʂׂ̈�(�]��)�R�[�h��
//	�������ꂽ�肷��\��������܂��B
//
//#define __USING_ANSI__
//#define __USING_SJIS__
//#define __USING_EUC__
//#define __USING_UTF8__

#	if !(defined(__USING_ANSI__) || defined(__USING_SJIS__) || defined(__USING_EUC__) || defined(__USING_UTF8__) || defined(__USING_UNKNOWN__))
#		define	__USING_UNKNOWN__
#	endif


//
//	���f�t�H���g������^�w��}�N��
//

//	�R���p�C�����Ɏw�肷��̂��ʓ|�ȏꍇ�͈ȉ��̃R�����g�s����K�؂Ȏw���
//	(�R�����g����������)�L��ɂ��Ă��������B�w�肳�ꂽ�^���e��e���v���[�g
//	�̃f�t�H���g�̌^�Ƃ��Ē�`����A(�ꕔ��)�e���v���[�g���g�p����ۂɌ^��
//	�w����ȗ��ł��܂��B
//
//#define __BBL_STRING_DEFAULT__
//#define __BBL_WSTRING_DEFAULT__

#	if !(defined(__BBL_STRING_DEFAULT__) || defined(__BBL_WSTRING_DEFAULT__))
#		define	__BBL_STRING_DEFAULT__
#	endif


//
//	�������ϊ��w��}�N��
//

//	�R���p�C�����Ɏw�肷��̂��ʓ|�ȏꍇ�͈ȉ��̃R�����g�s��(�R�����g������
//	����)�L��ɂ��Ă��������B���̃}�N�����w�肳���� EUC �y�� JIS ���� SJIS
//	�ւ̕ϊ��� UNICODE ���o�R���čs���܂��BUNICODE ���o�R���邱�Ƃɂ�� SJIS
//	�ł��\���\�Ȉꕔ�̕⏕�����𐳂����}�b�s���O���܂��B�������AUNICODE
//	���o�R���镪�������x�͗����܂��B�܂��A__BBL_DISABLE_UNICODE__ ����`��
//	��Ă��Ȃ����Ƃ��O��ƂȂ�܂��B
//
//#define __BBL_STRICT_TRANSLATE__


//
//	���}�b�s���O������@�w��}�N��
//

//	�R���p�C�����Ɏw�肷��̂��ʓ|�ȏꍇ�͈ȉ��̃R�����g�s����K�؂Ȏw���
//	(�R�����g����������)�L��ɂ��Ă��������B�f�t�H���g�̃}�b�s���O�Ɋւ���
//	�͎����w��}�N������`����Ă��Ȃ��Ă���������܂��B
//
//#define __BBL_USING_STATIC_TABLE__
//#define __BBL_USING_STDMAP_TABLE__

#	if defined(__BBL_USING_STATIC_TABLE__) && defined(__BBL_USING_STDMAP_TABLE__)
#		error	�}�b�s���O������@�w��}�N���͂ǂꂩ��ɂ��Ă��������B
#	endif

#	if !(defined(__BBL_USING_STATIC_TABLE__) || defined(__BBL_USING_STDMAP_TABLE__))
#		define	__BBL_USING_STATIC_TABLE__
#	endif



//
//	��UNICODE��Shift_JIS�}�b�s���O�����w��}�N��
//

//	�R���p�C�����Ɏw�肷��̂��ʓ|�ȏꍇ�͈ȉ��̃R�����g�s����K�؂Ȏw���
//	(�R�����g����������)�L��ɂ��Ă��������B�f�t�H���g�̃}�b�s���O�Ɋւ���
//	�͎����w��}�N������`����Ă��Ȃ��Ă���������܂��B
//
//		cf. �e��UNICODE�}�b�s���O�ɂ���
//			http://tricklib.com/cxx/ex/babel/#unicode_map
//
//#define __BBL_LOAD_UNICODE_MAP_CP932__
//#define __BBL_LOAD_UNICODE_MAP_UTC__
//#define __BBL_LOAD_UNICODE_MAP_APPLE__


//
//	��UNICODE��Shift_JIS�}�b�s���O�f�t�H���g�w��}�N��
//

//	�R���p�C�����Ɏw�肷��̂��ʓ|�ȏꍇ�͈ȉ��̃R�����g�s����K�؂Ȏw���
//	(�R�����g����������)�L��ɂ��Ă��������B
//
//		cf. �e��UNICODE�}�b�s���O�ɂ���
//			http://tricklib.com/cxx/ex/babel/#unicode_map
//
//#define __BBL_USE_UNICODE_MAP_CP932__
//#define __BBL_USE_UNICODE_MAP_UTC__
//#define __BBL_USE_UNICODE_MAP_APPLE__

#	if defined(__BBL_USE_UNICODE_MAP_CP932__) && defined(__BBL_USE_UNICODE_MAP_UTC__) || \
		defined(__BBL_USE_UNICODE_MAP_CP932__) && defined(__BBL_USE_UNICODE_MAP_APPLE__) || \
		defined(__BBL_USE_UNICODE_MAP_UTC__) && defined(__BBL_USE_UNICODE_MAP_APPLE__)
#		error	UNICODE��Shift_JIS�}�b�s���O�f�t�H���g�w��}�N���͂ǂꂩ��ɂ��Ă��������B
#	endif

#	if !(defined(__BBL_USE_UNICODE_MAP_CP932__) || defined(__BBL_USE_UNICODE_MAP_UTC__) || defined(__BBL_USE_UNICODE_MAP_APPLE__))
#		define	__BBL_USE_UNICODE_MAP_CP932__
#	endif

//	�t�Ӓ�`

#	if defined(__BBL_USE_UNICODE_MAP_CP932__) && !defined(__BBL_LOAD_UNICODE_MAP_CP932__)
#		define	__BBL_LOAD_UNICODE_MAP_CP932__
#	endif

#	if defined(__BBL_USE_UNICODE_MAP_UTC__) && !defined(__BBL_LOAD_UNICODE_MAP_UTC__)
#		define	__BBL_LOAD_UNICODE_MAP_UTC__
#	endif

#	if defined(__BBL_USE_UNICODE_MAP_APPLE__) && !defined(__BBL_LOAD_UNICODE_MAP_APPLE__)
#		define	__BBL_LOAD_UNICODE_MAP_APPLE__
#	endif


//
//	��Private Use Area �R�[�h��������w��}�N��
//

//	�R���p�C�����Ɏw�肷��̂��ʓ|�ȏꍇ�͈ȉ��̃R�����g�s��(�R�����g������
//	����)�L��ɂ��Ă��������B�f�t�H���g�̓���ł�UNICODE������(UTF-8���܂�)
//	���UNICODE������(SJIS,JIS,EUC)�ɕϊ�����ہAPrivate Use Area �̕����R�[
//	�h�͏�������܂����A���̃}�N�����w�肳��Ă���ꍇ�͏������܂���B(������
//	Private Use Area �̕����R�[�h�͈�ʓI�ɔ�UNICODE������ɐ������ϊ��ł�
//	�܂���̂� babel::bbl_term::broken_char �ɒu���������邾���ł��B)

//
//#define	__BBL_DISABLE_DISPEL_PRIVATE_USE_AREA__


//
//	���������ێw��}�N��
//

//	�R���p�C�����Ɏw�肷��̂��ʓ|�ȏꍇ�͈ȉ��̃R�����g�s����K�؂Ȏw���
//	(�R�����g����������)�L��ɂ��Ă��������B�f�t�H���g�̃}�b�s���O�Ɋւ���
//	�͎����w��}�N������`����Ă��Ȃ��Ă���������܂��B
//
//#define	__BBL_DISABLE_UNICODE__
//#define	__BBL_DISABLE_BINARY__
#define	__BBL_DISABLE_UTF32__	//	UTF-32 �̎����𑼂ł͌������Ȃ��̂Ńo�x���ł�(�������Ă����܂�Ӗ����Ȃ��̂�)�f�t�H���g�ł� off �B
//#define	__BBL_DISABLE_SELECTORS__

//	�ˑ��֌W

#	if defined(__BBL_DISABLE_UNICODE__)
#		if	defined(__BBL_LOAD_UNICODE_MAP_CP932__)
#			undef __BBL_LOAD_UNICODE_MAP_CP932__
#		endif
#		if	defined(__BBL_LOAD_UNICODE_MAP_UTC__)
#			undef __BBL_LOAD_UNICODE_MAP_UTC__
#		endif
#		if	defined(__BBL_LOAD_UNICODE_MAP_APPLE__)
#			undef __BBL_LOAD_UNICODE_MAP_APPLE__
#		endif
#		if	defined(__BBL_STRICT_TRANSLATE__)
#			undef __BBL_STRICT_TRANSLATE__
#		endif
#		if	!defined(__BBL_DISABLE_BINARY__)
#			define	__BBL_DISABLE_BINARY__
#		endif
#		if	!defined(__BBL_DISABLE_UTF32__)
#			define	__BBL_DISABLE_UTF32__
#		endif
#	endif

#	if defined(__BBL_DISABLE_BINARY__)
#		if	!defined(__BBL_DISABLE_UTF32__)
#			define	__BBL_DISABLE_UTF32__
#		endif
#	endif

//	�t�Ӓ�`

#	if !defined(__BBL_DISABLE_UNICODE__)
#		if	!defined(__BBL_USE_UNICODE__)
#			define	__BBL_USE_UNICODE__
#		endif
#	endif

#	if !defined(__BBL_DISABLE_BINARY__)
#		if	!defined(__BBL_USE_BINARY__)
#			define	__BBL_USE_BINARY__
#		endif
#	endif

#	if !defined(__BBL_DISABLE_UTF32__)
#		if	!defined(__BBL_USE_UTF32__)
#			define	__BBL_USE_UTF32__
#		endif
#	endif

#	if !defined(__BBL_DISABLE_SELECTORS__)
#		if	!defined(__BBL_USE_SELECTORS__)
#			define	__BBL_USE_SELECTORS__
#		endif
#	endif


//
//	EnBOM/DeBOM����������@
//

//#define __BBL_SMALL_BOM_LOGIC__
#define __BBL_LARGE_BOM_LOGIC__


/******************************************************************************
	��������                      TrickPalace                       ��������
	��������              http://www.trickpalace.net/               ��������
******************************************************************************/

#	if defined(__BORLANDC__)
#		pragma warn -8027
#	endif


//
//  ��babel
//
namespace babel {

//	���o�x�����W���[������֐���
void init_babel();


//
//	�N���X���֐���{�N���X�e���v���[�g(�Ƃ��� demi ���g��)
//
	template<class T> class bbl_demi {
		public:
			T value;

			bbl_demi() {}
			bbl_demi(const T &X_value) :value(X_value) {}
			bbl_demi(const bbl_demi<T> &X) :value(X.value) {}

			operator T& () { return value; }
			operator const T& () const { return value; }

			T * operator & () { return &value; }
			const T * operator & () const { return &value; }

			T & operator () () { return value; }
			const T & operator () () const { return value; }
	};
	//
	//	cf. http://tricklib.com/cxx/dagger/tips.h
	//

//
//  ���g�p���镶����N���X [ �Y ]
//
}
#include <string>

//
//	�o�x���ɑ΂���o�O�x�A�[�h�̓K�p
//
#if defined(__BABEL_WITH_BUG__)
//
//	�X�e�[�g�����g�n�b�N�n�m�I
//
#define __BUG_STATEMENT_HACK__	//	�X�e�[�g�����g�n�b�N�̎w��
#include "..\bugbeard\bug.h"
#endif	//	defined(__BABEL_WITH_BUG__)

namespace babel {
typedef std::string bbl_binary;
typedef std::string bbl_string;
#if	defined(__BBL_USE_UNICODE__)
//  typedef std::wstring bbl_wstring;	//	g++ �́R(�M�D�L)�m�{�P�F�I
typedef std::basic_string<wchar_t> bbl_wstring;
#endif	//	defined(__BBL_USE_UNICODE__)

inline const bbl_string & binary_to_string(const bbl_binary &X) { return X; }
inline const bbl_binary & string_to_binary(const bbl_string &X) { return X; }

#if defined(__BBL_STRING_DEFAULT__)
typedef	bbl_string	bbl_default_string;
#else
typedef	bbl_wstring	bbl_default_string;
#endif


//
//  ���^�[�� [ �Y ]
//
namespace bbl_term {
	const bbl_string broken_char = "?";		//	�Q�����ȏ�ł��AANSI�ȊO�͕s�B
	const bbl_string empty = "";
#if	defined(__BBL_USE_UNICODE__)
	const bbl_wstring broken_wchar = L"?";	//	�Q�����ȏ�ł��AANSI�ȊO�͕s�B
	const bbl_wstring wempty = L"";
#endif	//	defined(__BBL_USE_UNICODE__)
#if	defined(__BBL_USE_UNICODE__)
	const bbl_string utf8_FEFF = "\xEF\xBB\xBF";
//	const bbl_wstring unicode_bom = L"\uFEFF";	//	g++ �́R(�M�D�L)�m�{�P�F�I
	const bbl_wstring unicode_bom((bbl_wstring::size_type)1, (bbl_wstring::value_type)0xFEFF);
#endif	//	defined(__BBL_USE_UNICODE__)
	const bbl_string babel_version = "information>\n"
											"\tmodule>\tid=babel\n"
											"\t\tname=�o�x��  -babel- \n"
											"\t\turl=http://tricklib.com/cxx/ex/babel/\n"
											"\t\tversion=�x�[�^\n"
											"\tauthor>\tid=wraith\n"
											"\t\tname=�����t\n"
											"\t\turl=http://www.trickpalace.net/\n"
											"\t\tmail=wraith@trickpalace.net\n";

	struct get_broken_char {
		operator const bbl_string &() const { return broken_char; }
#if	defined(__BBL_USE_UNICODE__)
		operator const bbl_wstring &() const { return broken_wchar; }
#endif	//	defined(__BBL_USE_UNICODE__)
	};

#if	defined(__BBL_USE_UNICODE__)
	struct get_bom {
		operator const bbl_string &() const { return utf8_FEFF; }
		operator const bbl_wstring &() const { return unicode_bom; }
	};
#endif	//	defined(__BBL_USE_UNICODE__)

	struct get_empty {
		operator const bbl_string &() const { return empty; }
#if	defined(__BBL_USE_UNICODE__)
		operator const bbl_wstring &() const { return wempty; }
#endif	//	defined(__BBL_USE_UNICODE__)
	};
}

/******************************************************************************
	��������                       cppll ML                         ��������
	��������           http://www.trickpalace.net/cppll/            ��������
******************************************************************************/

#if	defined(__BBL_USE_UNICODE__)
inline const int get_base_wstring_size() {
	return sizeof(bbl_wstring::value_type);
}
#endif	//	defined(__BBL_USE_UNICODE__)

namespace base_endian {
	enum {
		unknown,
		little_endian,
		big_endian,
		bi_endian,
	};
};
inline const int get_base_endian() {
	using namespace base_endian;
#ifdef	__LITTLE_ENDIAN_COMPUTER__
	return little_endian;
#endif
#ifdef	__BIG_ENDIAN_COMPUTER__
	return big_endian;
#endif
#ifdef	__UNKNOWN_ENDIAN_COMPUTER__
	const int fingerprint = 0x01;
	return 0x01 == *((char*)&fingerprint) ? little_endian: big_endian;
#endif
}

namespace base_encoding {
	enum {
		unknown,
		binary,
		ansi,
		sjis,
		jis,
		euc,
		iso2022jp,
		utf8,
		utf16be,
		utf16le,
		utf32be,
		utf32le,
#ifdef	__LITTLE_ENDIAN_COMPUTER__
		utf16 = utf16le,
		utf32 = utf32le,
#endif
#ifdef	__BIG_ENDIAN_COMPUTER__
		utf16 = utf16be,
		utf32 = utf32be,
#endif
#ifdef	__UNKNOWN_ENDIAN_COMPUTER__
		utf16,
		utf32,
#endif
#ifdef	__UNICODE_CHAR_SIZE_2__
		unicode = utf16,
#endif
#ifdef	__UNICODE_CHAR_SIZE_4__
		unicode = utf32,
#endif
#ifdef	__UNICODE_CHAR_SIZE_UNKNOWN__
		unicode,
#endif
	};
};

//	��������ƗV��ł���������C�ɂ��Ȃ��ŁB

/*
template<class T, int size> class auto_array_class :public bbl_demi<T[size]>{
  public:
	auto_array_class(const T *X_value) {
		for(int i = 0; i < size; ++i) {
			value[i] = X_value[i];
		}
	}
	auto_array_class(const T *X_value, const T &X_value_end) {
		for(int i = 0; i < size -1; ++i) {
			value[i] = X_value[i];
		}
		value[size -1] = X_value_end;
	}
	auto_array_class<T, size +1> operator()(const T &X_value) {
		return auto_array_class<T, size +1>(value, X_value);
	}

	T & operator [] (unsigned int index) { return value[index]; }
	const T & operator [] (unsigned int index) const { return value[index]; }
};
template<class T> auto_array_class<T, 1> auto_array(const T &X_value) {
	return auto_array_class<T, 1>(&X_value);
}
*/

/*
template<class T, int size> class auto_array_class :public bbl_demi<T>{
	unsigned int index;
  public:
	auto_array_class(unsigned int X_index, const T &X_value) :index(X_index), bbl_demi(X_value) {
	}
	auto_array_class<T, size +1> operator()(const T &X_value) {
		return auto_array_class<T, size +1>(index, (index == size) ? X_value: value);
	}
};
template<class T> auto_array_class<T, 0> auto_array(unsigned int index, const T &default_value = T()) {
	return auto_array_class<T, 0>(index, default_value);
}
*/

/*
template<class T> const T & get_array_item(unsigned int index, const T &first_item...) {
	if (0 == index) {
		return first_item;
	}
	va_list X;
	va_start(X, first_item);
	for(unsinged int i = 1; i < index; ++i) {
		va_arg(X, T);
	}
	const T &item = va_arg(X, T);
	va_end(X);
	return item;

//	return *(index + &first_item);
}
*/

//	��������ƗV��ł���������C�ɂ��Ȃ��ŁB


namespace profile_for_UI {
	//	get_list_size_for_UI(), get_id_for_UI(), get_name_for_UI() �͎O��
	//	�Z�b�g�̊֐��ł��B���[�U�ɃG���R�[�h���w�肳����ꍇ�ɂ����p���������B
	inline const unsigned int get_list_size_for_UI() {
#if	defined(__BBL_USE_UNICODE__)
		return 5;
#else	//	defined(__BBL_USE_UNICODE__)
#	if	defined(__BBL_USE_UTF32__)
		return 8;
#	else	//	defined(__BBL_USE_UTF32__)
		return 10;
#	endif	//	defined(__BBL_USE_UTF32__)
#endif	//	defined(__BBL_USE_UNICODE__)
	}
	inline const int get_id_for_UI(unsigned int index) {
		assert(index < get_list_size_for_UI());
		using namespace base_encoding;
		const int id_for_UI[] = {
				ansi,
				sjis,
				jis,
				euc,
				iso2022jp,
#if	defined(__BBL_USE_UNICODE__)
				utf8,
				utf16be,
				utf16le,
#	if	defined(__BBL_USE_UTF32__)
				utf32be,
				utf32le,
#	endif	//	defined(__BBL_USE_UTF32__)
#endif	//	defined(__BBL_USE_UNICODE__)
		};
		assert(sizeof(id_for_UI) /sizeof(id_for_UI[0]) == get_list_size_for_UI());
		return id_for_UI[index];
	//	return auto_array(ansi)(sjis)(jis)(euc)(iso2022jp)(utf8)
	//						(utf16be)(utf16le)(utf32be)(utf32le)[index];
	//	return get_array_item(index, ansi, sjis, jis, euc, iso2022jp, utf8,
	//						utf16be, utf16le, utf32be, utf32le);
	}
	inline const bbl_string get_name_for_UI(unsigned int index) {
		assert(index < get_list_size_for_UI());
		const char * name_for_UI[] = {
			"ANSI",
			"�V�t�gJIS",
			"JIS(���p�J�i��)",
			"EUC-JP",
			"ISO-2022-JP",
#if	defined(__BBL_USE_UNICODE__)
			"UTF-8",
			"UTF-16",
			"UTF-16le",
#	if	defined(__BBL_USE_UTF32__)
			"UTF-32",
			"UTF-32le",
#	endif	//	defined(__BBL_USE_UTF32__)
#endif	//	defined(__BBL_USE_UNICODE__)
		};
		return name_for_UI[index];
	//	return auto_array("ANSI")("�V�t�gJIS")("JIS(���p�J�i��)")("EUC-JP")
	//						("ISO-2022-JP")("UTF-8")("UTF-16")
	//						("UTF-16le")("UTF-32")("UTF-32le")[index];
	}

	//	get_base_encoding_name()�̓G���R�[�h��ID����\���p�̕�������擾�����
	//	�̊֐��ł����Aget_name_for_UI()�ƍ������Ȃ��悤�ɋC�����Ă��������B
	inline const bbl_string get_base_encoding_name(unsigned int index) {
		const char *base_encoding_name[] = {
			"�s��",
			"�o�C�i��",
			"ANSI",
			"�V�t�gJIS",
			"JIS(���p�J�i��)",
			"EUC-JP",
			"ISO-2022-JP",
			"UTF-8",
			"UTF-16be",
			"UTF-16le",
			"UTF-32be",
			"UTF-32le",
			"UTF-16",
			"UTF-32",
		};
		return base_encoding_name[index];
	}
}


inline const int get_base_encoding() {
	using namespace base_encoding;
#ifdef	__USING_ANSI__
	return ansi;
#endif
#ifdef	__USING_SJIS__
	return sjis;
#endif
#ifdef	__USING_EUC__
	return euc;
#endif
#ifdef	__USING_UTF8__
	return utf8;
#endif
#ifdef	__USING_UNKNOWN__
	const int fingerprint = ((unsigned char*)("����"))[0];
	if (0x8A == fingerprint) {
		return sjis;
	}
	if (0x84 == fingerprint) {
		return euc;
	}
	if (0xE6 == fingerprint) {
		return utf8;
	}
	return ansi;
#endif
}


bbl_binary::size_type get_aspect_position(const bbl_binary &X);

class analyze_result {
	typedef int value_type;
	const value_type hunch_result;
	const value_type strict_result;
  public:
	analyze_result(const value_type X_hunch_result)
		:hunch_result(X_hunch_result), strict_result(X_hunch_result) { }
	analyze_result(
			const value_type X_hunch_result,
			const value_type X_strict_result)
		:hunch_result(X_hunch_result), strict_result(X_strict_result) { }
	const int & get_hunch_result() const { return hunch_result; }
	const int & get_strict_result() const { return strict_result; }
	operator const int &() const { return get_hunch_result(); }
};
analyze_result analyze_base_encoding(const bbl_binary &X, const unsigned int max_scan_size = 8192);

class bbl_smart_base {
  public:
	typedef bbl_smart_base this_type;
  private:
	volatile int ref_count;
  protected:
	bbl_smart_base() :ref_count(0) {}
	virtual ~bbl_smart_base() { assert(0 == ref_count); }

  public:
	void inc_ref() volatile {
		if (NULL != this) {
			++ref_count;
		}
	}
	void dec_ref() volatile {
		if (NULL != this) {
			if (--ref_count <= 0) {
				assert(0 == ref_count);
				delete this;
			}
		}
	}
};
template<class target_object>
class bbl_smart_shell {
  public:
	typedef bbl_smart_shell<target_object> this_type;
	typedef target_object	target_type;

  private:
	target_type *value;

  public:
	bbl_smart_shell(target_type *X_value = NULL) :value(X_value) {
		value->inc_ref();
	}
	bbl_smart_shell(const this_type &X) :value(X.value) {
		value->inc_ref();
	}
	~bbl_smart_shell() {
		value->dec_ref();
	}

	this_type & operator = (target_type *X_value) {
		if (value != X_value) {
			value->dec_ref();
			value = X_value;
			value->inc_ref();
		}
		return *this;
	}
	this_type & operator = (const this_type &X) {
		if (value != X.value) {
			value->dec_ref();
			value = X.value;
			value->inc_ref();
		}
		return *this;
	}

	bool operator == (const this_type &X) const {
		return value == X.value;
	}
	bool operator != (const this_type &X) const {
		return value != X.value;
	}
	bool operator == (const target_type *X_value) const {
		return value == X_value;
	}
	bool operator != (const target_type *X_value) const {
		return value != X_value;
	}

	bool operator ! () const { return !value; }
	operator target_type* () { return value; }
	operator const target_type* () const { return value; }
	target_type& operator*() { return *value; }
	const target_type& operator*() const { return *value; }
	target_type* operator->() { return value; }
	const target_type* operator->() const { return value; }
	bool is_null() const { return NULL == value; }
	bool is_not_null() const { return NULL != value; }
};

template<class from_string = bbl_default_string, class to_string = bbl_default_string> class bbl_translater;

template<class from_string = bbl_default_string, class to_string = bbl_default_string>
class bbl_translate_engine :public bbl_smart_base {
  public:
	typedef bbl_translate_engine<from_string, to_string> this_type;
	typedef bbl_translater<from_string, to_string> bbl_translater_type;
	typedef from_string		from_string_type;
	typedef to_string		to_string_type;
//	friend class bbl_translater_type;
	friend class bbl_translater<from_string, to_string>; //	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	from_string_type untranslated_buffer;
	to_string_type translated_buffer;
  public:
	virtual void translate() = 0;
	virtual void flush() {
		for(int i = 0, length = untranslated_buffer.length(); i < length; ++i) {
			translated_buffer += bbl_term::get_broken_char();
		}
		untranslated_buffer = bbl_term::get_empty();
	}
	virtual void clear() {
		untranslated_buffer = bbl_term::get_empty();
		translated_buffer = bbl_term::get_empty();
	}

	const to_string_type & ignite(const from_string_type &X) {
		untranslated_buffer = X;
		translate();
		flush();
		return translated_buffer;
	}
};

//
//	�����\�ϊ��G���W��
//
template<class from_string = bbl_default_string, class to_string = bbl_default_string>
class dull_engine :public bbl_translate_engine<from_string, to_string> {
  public:
	typedef dull_engine<from_string, to_string> this_type;
	typedef	bbl_translate_engine<from_string, to_string> base_type;
	typedef typename base_type::bbl_translater_type	bbl_translater_type;
//	typedef typename base_type::from_string_type	from_string_type;
//	typedef typename base_type::to_string_type		to_string_type;
	typedef from_string						from_string_type;	//	bcc �́R(�M�D�L)�m�΂����I
	typedef to_string						to_string_type;		//	bcc �́R(�M�D�L)�m�΂����I
  private:
	dull_engine() {}
  public:	//	�����ʂȌx������̈� ... g++ �́R(�M�D�L)�m�{�P�F�I
	~dull_engine() {}	//	bcc �́R(�M�D�L)�m�΂����I
  protected:
	void translate() { }
	void flush() { base_type::untranslated_buffer = bbl_term::get_empty(); }
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return bbl_term::get_empty(); }
};

template<class first_engine, class second_engine> class twin_translate_engine;

//
//	���R�[�h�ϊ��N���X(�G���W���̃V�F��)
//
template<class from_string, class to_string>	//	��s�錾�Ŋ�Ɏw�肵�Ă���̂ł����ł̓f�t�H���g���w�肵�Ȃ��B
class bbl_translater {
  public:
	typedef bbl_translater this_type;
	typedef bbl_translate_engine<from_string, to_string> engine_type;
	typedef dull_engine<from_string, to_string> dull_engine_type;
	typedef from_string		from_string_type;
	typedef to_string		to_string_type;

  private:
	bbl_smart_shell<engine_type> engine;
  public:
	bbl_translater(engine_type *X_engine)	:engine(X_engine) { }
	bbl_translater(const bbl_translater &X = dull_engine_type::create())
										:engine(X.engine) { }
	~bbl_translater() { }

	bbl_translater & operator = (engine_type *X_engine) {
		engine = X_engine;
		return *this;
	}
	bbl_translater & operator = (const bbl_translater &X) {
		engine = X.engine;
		return *this;
	}
	bool operator == (const bbl_translater &X) const {
		return engine == X.engine;
	}
	bool operator != (const bbl_translater &X) const {
		return engine != X.engine;
	}

	this_type & translate(const from_string_type &X) {
		engine->untranslated_buffer += X;
		engine->translate();
		return *this;
	}
	this_type & flush() {
		//engine->translate();
		engine->flush();
		return *this;
	}
	this_type & clear() {
		engine->clear();
		//���K�������o�b�t�@���N���A�����Ƃ͌���Ȃ��̂ł��̓�� assert �̓R�����g�A�E�g���܂����B
		//assert(0 == engine->untranslated_buffer.length());
		//assert(0 == engine->translated_buffer.length());
		return *this;
	}

	this_type & operator = (const from_string_type &X) { return clear().translate(X).flush(); }
	operator const to_string_type & () const { return get_string(); }
	const to_string_type & get_string() const { return engine->translated_buffer;	}
	const char * c_str() const { return get_string().c_str(); }
	const to_string_type pook_buffer() {
		to_string_type buffer = engine->translated_buffer;
//		engine->translated_buffer.clear();	//	g++ �́R(�M�D�L)�m�{�P�F�I
		engine->translated_buffer.erase();
		return buffer;
	}

	this_type & operator << (const from_string_type &X) { return translate(X); }
	this_type & operator >> (to_string_type &X) {
		X = engine->translated_buffer;
//		engine->translated_buffer.clear();	//	g++ �́R(�M�D�L)�m�{�P�F�I
		engine->translated_buffer.erase();
		return *this;
	}
	const to_string_type & operator () (const from_string_type &X) {
		return clear().translate(X).flush().get_string();
	}
};

template<class target_string = bbl_default_string>
class through_engine :public bbl_translate_engine<target_string, target_string> {
  public:
	typedef through_engine<target_string>	this_type;
	typedef	bbl_translate_engine<target_string, target_string> base_type;
	typedef typename base_type::bbl_translater_type	bbl_translater_type;
	typedef typename base_type::from_string_type	from_string_type;
	typedef typename base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	through_engine() {}
  protected:
	void translate() {
		base_type::translated_buffer += base_type::untranslated_buffer;
//		untranslated_buffer.clear();	//	g++ �́R(�M�D�L)�m�{�P�F�I
		base_type::untranslated_buffer.erase();
	}
	void flush() { }
  public:
static bbl_translater_type create() { return new this_type; }
//	static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
static const to_string_type & ignite(const from_string_type &X) { return X; }
};

#if	defined(__BBL_USE_UNICODE__)
class ansi_to_unicode_engine :public bbl_translate_engine<bbl_string, bbl_wstring> {
  public:
	typedef ansi_to_unicode_engine this_type;
	typedef bbl_translate_engine<bbl_string, bbl_wstring> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	ansi_to_unicode_engine() { }
  protected:
	void translate();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};

class unicode_to_ansi_engine :public bbl_translate_engine<bbl_wstring, bbl_string> {
  public:
	typedef unicode_to_ansi_engine this_type;
	typedef bbl_translate_engine<bbl_wstring, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	unicode_to_ansi_engine() { }
  protected:
	void translate();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
#endif	//	defined(__BBL_USE_UNICODE__)

class sjis_to_euc_engine :public bbl_translate_engine<bbl_string, bbl_string> {
  public:
	typedef sjis_to_euc_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	sjis_to_euc_engine() { }
  protected:
	void translate();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class sjis_to_jis_engine :public bbl_translate_engine<bbl_string, bbl_string> {
  public:
	typedef sjis_to_jis_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	int status;
	sjis_to_jis_engine() :status(0) { }
  protected:
	void translate();
	void flush();
	void clear() {
		base_type::clear();
		status = 0;
	}
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};

#if	defined(__BBL_USE_UNICODE__)
#	if defined(__BBL_USE_UNICODE_MAP_CP932__)
class unicode_to_sjis_cp932_engine;
typedef unicode_to_sjis_cp932_engine	unicode_to_sjis_engine;
class sjis_cp932_to_unicode_engine;
typedef sjis_cp932_to_unicode_engine	sjis_to_unicode_engine;
#	endif
#	if defined(__BBL_USE_UNICODE_MAP_UTC__)
class unicode_to_sjis_utc_engine;
typedef unicode_to_sjis_utc_engine		unicode_to_sjis_engine;
class sjis_utc_to_unicode_engine;
typedef sjis_utc_to_unicode_engine		sjis_to_unicode_engine;
#	endif
#	if defined(__BBL_USE_UNICODE_MAP_APPLE__)
class unicode_to_sjis_apple_engine;
typedef unicode_to_sjis_apple_engine	unicode_to_sjis_engine;
class sjis_apple_to_unicode_engine
typedef sjis_apple_to_unicode_engine	sjis_to_unicode_engine;
#	endif
#endif	//	defined(__BBL_USE_UNICODE__)

#if	defined(__BBL_STRICT_TRANSLATE__)
class euc_to_unicode_engine;
typedef twin_translate_engine<euc_to_unicode_engine, unicode_to_sjis_engine> euc_to_sjis_engine;
#else	//	defined(__BBL_STRICT_TRANSLATE__);
class euc_to_sjis_engine :public bbl_translate_engine<bbl_string, bbl_string> {
  public:
	typedef euc_to_sjis_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	euc_to_sjis_engine() { }
  protected:
	void translate();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
#endif	//	defined(__BBL_STRICT_TRANSLATE__);
class euc_to_jis_engine :public bbl_translate_engine<bbl_string, bbl_string> {
  public:
	typedef euc_to_jis_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	int status;
	euc_to_jis_engine() :status(0) { }
  protected:
	void translate();
	void flush();
	void clear() {
		base_type::clear();
		status = 0;
	}
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};

#if	defined(__BBL_USE_UNICODE__)
class euc_to_unicode_engine :public bbl_translate_engine<bbl_string, bbl_wstring> {
  public:
	typedef euc_to_unicode_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_wstring> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	euc_to_unicode_engine() {
#ifdef	__BBL_SMALL_BOM_LOGIC__
		translated_buffer = bbl_term::unicode_bom;
#endif	//	__BBL_SMALL_BOM_LOGIC__
	}
  protected:
	void translate();
#ifdef	__BBL_SMALL_BOM_LOGIC__
	void clear() {
		base_type::clear();
		translated_buffer = bbl_term::unicode_bom;
	}
#endif	//	__BBL_SMALL_BOM_LOGIC__
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class unicode_to_euc_engine :public bbl_translate_engine<bbl_wstring, bbl_string> {
  public:
	typedef unicode_to_euc_engine this_type;
	typedef	bbl_translate_engine<bbl_wstring, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	unicode_to_euc_engine() { }
  protected:
	void translate();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
#endif	//	defined(__BBL_USE_UNICODE__)

#if	defined(__BBL_STRICT_TRANSLATE__)
class jis_to_euc_engine;
typedef twin_translate_engine<jis_to_euc_engine, euc_to_sjis_engine> jis_to_sjis_engine;
#else	//	defined(__BBL_STRICT_TRANSLATE__);
class jis_to_sjis_engine :public bbl_translate_engine<bbl_string, bbl_string> {
  public:
	typedef jis_to_sjis_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	int status;
	jis_to_sjis_engine() :status(0) { }
  protected:
	void translate();
	void flush();
	void clear() {
		base_type::clear();
		status = 0;
	}
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
#endif	//  defined(__BBL_STRICT_TRANSLATE__)
class jis_to_euc_engine :public bbl_translate_engine<bbl_string, bbl_string> {
  public:
	typedef jis_to_euc_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	int status;
	jis_to_euc_engine() :status(0) { }
  protected:
	void translate();
	void flush();
	void clear() {
		base_type::clear();
		status = 0;
	}
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class jis_to_iso2022jp_engine :public bbl_translate_engine<bbl_string, bbl_string> {
  public:
	typedef jis_to_iso2022jp_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	int from_status;
	int to_status;
	jis_to_iso2022jp_engine() :from_status(0), to_status(0) { }
  protected:
	void translate();
	void flush();
	void clear() {
		base_type::clear();
		from_status = 0;
		to_status = 0;
	}
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};

#if defined(__BBL_LOAD_UNICODE_MAP_CP932__)
class sjis_cp932_to_unicode_engine :public bbl_translate_engine<bbl_string, bbl_wstring> {
  public:
	typedef sjis_cp932_to_unicode_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_wstring> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	sjis_cp932_to_unicode_engine() {
#ifdef	__BBL_SMALL_BOM_LOGIC__
		translated_buffer = bbl_term::unicode_bom;
#endif	//	__BBL_SMALL_BOM_LOGIC__
	}
  protected:
	void translate();
#ifdef	__BBL_SMALL_BOM_LOGIC__
	void clear() {
		base_type::clear();
		translated_buffer = bbl_term::unicode_bom;
	}
#endif	//	__BBL_SMALL_BOM_LOGIC__
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class unicode_to_sjis_cp932_engine :public bbl_translate_engine<bbl_wstring, bbl_string> {
  public:
	typedef unicode_to_sjis_cp932_engine this_type;
	typedef	bbl_translate_engine<bbl_wstring, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	unicode_to_sjis_cp932_engine() { }
  protected:
	void translate();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
#endif	//	defined(__BBL_LOAD_UNICODE_MAP_CP932__)

#if defined(__BBL_LOAD_UNICODE_MAP_UTC__)
class sjis_utc_to_unicode_engine :public bbl_translate_engine<bbl_string, bbl_wstring> {
  public:
	typedef sjis_utc_to_unicode_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_wstring> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	sjis_utc_to_unicode_engine() {
#ifdef	__BBL_SMALL_BOM_LOGIC__
		translated_buffer = bbl_term::unicode_bom;
#endif	//	__BBL_SMALL_BOM_LOGIC__
	}
  protected:
	void translate();
#ifdef	__BBL_SMALL_BOM_LOGIC__
	void clear() {
		base_type::clear();
		translated_buffer = bbl_term::unicode_bom;
	}
#endif	//	__BBL_SMALL_BOM_LOGIC__
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class unicode_to_sjis_utc_engine :public bbl_translate_engine<bbl_wstring, bbl_string> {
  public:
	typedef unicode_to_sjis_utc_engine this_type;
	typedef	bbl_translate_engine<bbl_wstring, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	unicode_to_sjis_utc_engine() { }
  protected:
	void translate();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
#endif	//	defined(__BBL_LOAD_UNICODE_MAP_UTC__)

#if defined(__BBL_LOAD_UNICODE_MAP_APPLE__)
class sjis_apple_to_unicode_engine :public bbl_translate_engine<bbl_string, bbl_wstring> {
  public:
	typedef sjis_apple_to_unicode_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_wstring> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	sjis_apple_to_unicode_engine() {
#ifdef	__BBL_SMALL_BOM_LOGIC__
		translated_buffer = bbl_term::unicode_bom;
#endif	//	__BBL_SMALL_BOM_LOGIC__
	}
  protected:
	void translate();
#ifdef	__BBL_SMALL_BOM_LOGIC__
	void clear() {
		base_type::clear();
		translated_buffer = bbl_term::unicode_bom;
	}
#endif	//	__BBL_SMALL_BOM_LOGIC__
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class unicode_to_sjis_apple_engine :public bbl_translate_engine<bbl_wstring, bbl_string> {
  public:
	typedef unicode_to_sjis_apple_engine this_type;
	typedef	bbl_translate_engine<bbl_wstring, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	unicode_to_sjis_apple_engine() { }
  protected:
	void translate();
	void flush();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
#endif	//	defined(__BBL_LOAD_UNICODE_MAP_APPLE__)

#if	defined(__BBL_USE_UNICODE__)
class unicode_to_utf8_engine :public bbl_translate_engine<bbl_wstring, bbl_string> {
  public:
	typedef unicode_to_utf8_engine this_type;
	typedef	bbl_translate_engine<bbl_wstring, bbl_string> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	unicode_to_utf8_engine() { }
  protected:
	void translate();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class utf8_to_unicode_engine :public bbl_translate_engine<bbl_string, bbl_wstring> {
  public:
	typedef utf8_to_unicode_engine this_type;
	typedef	bbl_translate_engine<bbl_string, bbl_wstring> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	utf8_to_unicode_engine() { }
  protected:
	void translate();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};

#ifdef	__BBL_LARGE_BOM_LOGIC__
template<class target_string = bbl_default_string>
class enbom_engine :public through_engine<target_string> {
  public:
	typedef enbom_engine<target_string>		this_type;
	typedef	through_engine<target_string>	base_type;
	typedef typename base_type::bbl_translater_type	bbl_translater_type;
	typedef typename base_type::from_string_type	from_string_type;
	typedef typename base_type::to_string_type		to_string_type;
  private:
	enbom_engine() {
		base_type::translated_buffer = bbl_term::get_bom();
	}
  protected:
	void clear() {
		base_type::clear();
		base_type::translated_buffer = bbl_term::get_bom();
	}
  public:
static bbl_translater_type create() { return new this_type; }
//static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }	//	VC �́R(�M�D�L)�m�A�z�H�I
static const to_string_type ignite(const from_string_type &X) { return enbom_engine<target_string>().through_engine<target_string>::ignite(X); }
};

template<class target_string = bbl_default_string>
class debom_engine :public through_engine<target_string> {
  public:
	typedef debom_engine<target_string>		this_type;
	typedef	through_engine<target_string>	base_type;
	typedef typename base_type::bbl_translater_type	bbl_translater_type;
	typedef typename base_type::from_string_type	from_string_type;
	typedef typename base_type::to_string_type		to_string_type;
  private:
	debom_engine() {}
  protected:
	void translate() {
		typename from_string_type::size_type p_bom;
		while(from_string_type::npos != (p_bom = base_type::untranslated_buffer.find(bbl_term::get_bom()))) {
			base_type::untranslated_buffer.erase(p_bom, 1);
		}
		base_type::translate();
	}
  public:
static bbl_translater_type create() { return new this_type; }
//static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }	//	VC �́R(�M�D�L)�m�A�z�H�I
static const to_string_type ignite(const from_string_type &X) { return debom_engine<target_string>().through_engine<target_string>::ignite(X); }
};
#endif	//	__BBL_LARGE_BOM_LOGIC__


#endif	//	defined(__BBL_USE_UNICODE__)

const int translate_buffer_full_size = 1024;	//	8�`4096
const int translate_buffer_size = 1000;			//	translate_buffer_full_size -��
//const int translate_buffer_full_size = 128;		//	8�`4096
//const int translate_buffer_size = 100;			//	translate_buffer_full_size -��

//
//	�������ϊ��G���W��
//
template<class first_engine, class second_engine>
class twin_translate_engine :public bbl_translate_engine<typename first_engine::from_string_type, typename second_engine::to_string_type> {
  public:
	typedef twin_translate_engine<first_engine, second_engine> this_type;
	typedef first_engine	first_engine_type;
	typedef	second_engine	second_engine_type;
	typedef	bbl_translate_engine<typename first_engine::from_string_type, typename second_engine::to_string_type> base_type;
	typedef typename base_type::bbl_translater_type	bbl_translater_type;
	typedef typename base_type::from_string_type	from_string_type;
	typedef typename base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	typename first_engine_type::bbl_translater_type engine1;
	typename second_engine_type::bbl_translater_type engine2;

	twin_translate_engine()
		:engine1(first_engine_type::create()),
		engine2(second_engine_type::create()) { }

  protected:
	void translate() {
		engine1.translate(base_type::untranslated_buffer);
//		untranslated_buffer.clear();	//	g++ �́R(�M�D�L)�m�{�P�F�I
		base_type::untranslated_buffer.erase();
		engine2.translate(engine1.pook_buffer());
		base_type::translated_buffer += engine2.pook_buffer();
	}
	void flush() {
		engine1.flush();

//		untranslated_buffer.clear();	//	g++ �́R(�M�D�L)�m�{�P�F�I
		base_type::untranslated_buffer.erase();
		engine2.translate(engine1.pook_buffer()).flush();
		base_type::translated_buffer += engine2.pook_buffer();
	}
	void clear() {
		base_type::clear();
		engine1.clear();
		engine2.clear();
	}
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) {
		return second_engine_type::ignite(first_engine_type::ignite(X));
//		return this_type().base_type::ignite(X);
	}
};

#if	defined(__BBL_USE_UNICODE__)
typedef twin_translate_engine<jis_to_euc_engine, euc_to_unicode_engine> jis_to_unicode_engine;
typedef twin_translate_engine<unicode_to_euc_engine, euc_to_jis_engine> unicode_to_jis_engine;
typedef twin_translate_engine<sjis_to_unicode_engine, unicode_to_utf8_engine> sjis_to_utf8_engine;
typedef twin_translate_engine<euc_to_unicode_engine, unicode_to_utf8_engine> euc_to_utf8_engine;
typedef twin_translate_engine<jis_to_unicode_engine, unicode_to_utf8_engine> jis_to_utf8_engine;
typedef twin_translate_engine<utf8_to_unicode_engine, unicode_to_sjis_engine> utf8_to_sjis_engine;
typedef twin_translate_engine<utf8_to_unicode_engine, unicode_to_euc_engine> utf8_to_euc_engine;
typedef twin_translate_engine<utf8_to_euc_engine, euc_to_jis_engine> utf8_to_jis_engine;
//typedef twin_translate_engine<euc_to_sjis_engine, sjis_to_unicode_engine> euc_to_unicode_engine;
//typedef twin_translate_engine<unicode_to_sjis_engine, sjis_to_euc_engine> unicode_to_euc_engine;
#endif	//	defined(__BBL_USE_UNICODE__)

//
//	���R�[�h�ϊ��֐�(�G�C���A�X)
//
const bbl_string (* const sjis_to_euc)(const bbl_string &) = sjis_to_euc_engine::ignite;
const bbl_string (* const sjis_to_jis)(const bbl_string &) = sjis_to_jis_engine::ignite;
const bbl_string (* const euc_to_sjis)(const bbl_string &) = euc_to_sjis_engine::ignite;
const bbl_string (* const euc_to_jis)(const bbl_string &) = euc_to_jis_engine::ignite;
const bbl_string (* const jis_to_sjis)(const bbl_string &) = jis_to_sjis_engine::ignite;
const bbl_string (* const jis_to_euc)(const bbl_string &) = jis_to_euc_engine::ignite;
const bbl_string (* const jis_to_iso2022jp)(const bbl_string &) = jis_to_iso2022jp_engine::ignite;
#if	defined(__BBL_USE_UNICODE__)
const bbl_string (* const sjis_to_utf8)(const bbl_string &) = sjis_to_utf8_engine::ignite;
const bbl_wstring (* const sjis_to_unicode)(const bbl_string &) = sjis_to_unicode_engine::ignite;
const bbl_string (* const euc_to_utf8)(const bbl_string &) = euc_to_utf8_engine::ignite;
const bbl_wstring (* const euc_to_unicode)(const bbl_string &) = euc_to_unicode_engine::ignite;
const bbl_string (* const jis_to_utf8)(const bbl_string &) = jis_to_utf8_engine::ignite;
const bbl_wstring (* const jis_to_unicode)(const bbl_string &) = jis_to_unicode_engine::ignite;
const bbl_string (* const utf8_to_sjis)(const bbl_string &) = utf8_to_sjis_engine::ignite;
const bbl_string (* const utf8_to_euc)(const bbl_string &) = utf8_to_euc_engine::ignite;
const bbl_string (* const utf8_to_jis)(const bbl_string &) = utf8_to_jis_engine::ignite;
const bbl_wstring (* const utf8_to_unicode)(const bbl_string &) = utf8_to_unicode_engine::ignite;
const bbl_string (* const unicode_to_sjis)(const bbl_wstring &) = unicode_to_sjis_engine::ignite;
const bbl_string (* const unicode_to_euc)(const bbl_wstring &) = unicode_to_euc_engine::ignite;
const bbl_string (* const unicode_to_jis)(const bbl_wstring &) = unicode_to_jis_engine::ignite;
const bbl_string (* const unicode_to_utf8)(const bbl_wstring &) = unicode_to_utf8_engine::ignite;
#endif	//	defined(__BBL_USE_UNICODE__)


/******************************************************************************
	��������                          cuppa                         ��������
	��������                 http://www.unittest.org/               ��������
******************************************************************************/

#if defined(__BBL_USE_BINARY__)
class WORD_to_unicode_engine :public bbl_translate_engine<bbl_binary, bbl_wstring> {
  public:
	typedef WORD_to_unicode_engine this_type;
	typedef	bbl_translate_engine<bbl_binary, bbl_wstring> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	WORD_to_unicode_engine() { }
  protected:
	void translate();
	void flush();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class unicode_to_WORD_engine :public bbl_translate_engine<bbl_wstring, bbl_binary> {
  public:
	typedef unicode_to_WORD_engine this_type;
	typedef	bbl_translate_engine<bbl_wstring, bbl_binary> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	unicode_to_WORD_engine() { }
  protected:
	void translate();
	void flush();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class cross_WORD_to_unicode_engine :public bbl_translate_engine<bbl_binary, bbl_wstring> {
  public:
	typedef cross_WORD_to_unicode_engine this_type;
	typedef	bbl_translate_engine<bbl_binary, bbl_wstring> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	cross_WORD_to_unicode_engine() { }
  protected:
	void translate();
	void flush();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class unicode_to_cross_WORD_engine :public bbl_translate_engine<bbl_wstring, bbl_binary> {
  public:
	typedef unicode_to_cross_WORD_engine this_type;
	typedef	bbl_translate_engine<bbl_wstring, bbl_binary> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	unicode_to_cross_WORD_engine() { }
  protected:
	void translate();
	void flush();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};

const bbl_wstring WORD_to_unicode(const bbl_binary &X);
const bbl_binary unicode_to_WORD(const bbl_wstring &X);
const bbl_wstring cross_WORD_to_unicode(const bbl_binary &X);
const bbl_binary unicode_to_cross_WORD(const bbl_wstring &X);

inline const unsigned int WORD_cross_endian(const unsigned int &X) {
	assert(X <= 0xFFFF);
	return ((X &0x00FF) *0x100)
		|(X /0x100);
}


#	if	defined(__BBL_USE_UTF32__)
class DWORD_to_unicode_engine :public bbl_translate_engine<bbl_binary, bbl_wstring> {
  public:
	typedef DWORD_to_unicode_engine this_type;
	typedef	bbl_translate_engine<bbl_binary, bbl_wstring> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	DWORD_to_unicode_engine() { }
  protected:
	void translate();
	void flush();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class unicode_to_DWORD_engine :public bbl_translate_engine<bbl_wstring, bbl_binary> {
  public:
	typedef unicode_to_DWORD_engine this_type;
	typedef	bbl_translate_engine<bbl_wstring, bbl_binary> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	unicode_to_DWORD_engine() { }
  protected:
	void translate();
	void flush();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class cross_DWORD_to_unicode_engine :public bbl_translate_engine<bbl_binary, bbl_wstring> {
  public:
	typedef cross_DWORD_to_unicode_engine this_type;
	typedef	bbl_translate_engine<bbl_binary, bbl_wstring> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	cross_DWORD_to_unicode_engine() { }
  protected:
	void translate();
	void flush();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};
class unicode_to_cross_DWORD_engine :public bbl_translate_engine<bbl_wstring, bbl_binary> {
  public:
	typedef unicode_to_cross_DWORD_engine this_type;
	typedef	bbl_translate_engine<bbl_wstring, bbl_binary> base_type;
	typedef base_type::bbl_translater_type	bbl_translater_type;
	typedef base_type::from_string_type		from_string_type;
	typedef base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	unicode_to_cross_DWORD_engine() { }
  protected:
	void translate();
	void flush();
  public:
static bbl_translater_type create() { return new this_type; }
static const to_string_type ignite(const from_string_type &X) { return this_type().base_type::ignite(X); }
};

const bbl_wstring DWORD_to_unicode(const bbl_binary &X);
const bbl_binary unicode_to_DWORD(const bbl_wstring &X);
const bbl_wstring cross_DWORD_to_unicode(const bbl_binary &X);
const bbl_binary unicode_to_cross_DWORD(const bbl_wstring &X);

inline const unsigned int DWORD_cross_endian(const unsigned int &X) {
	return (X *0x1000000)
		|((X &0x0000FF00) *0x100)
		|((X &0x00FF0000) /0x100)
		|(X /0x1000000);
}
#	endif	//defined(__BBL_USE_UTF32__)

#endif	//	defined(__BBL_USE_BINARY__)


#if defined(__BBL_USE_SELECTORS__)
//
//	��translate_to_string-, auto_translate-, translate_to_binary-, manual_translate-
//

//	���g������
//
//	translate_engine get_translate_engine(�ړI, �G���R�[�h�^�C�v���������Ă��� = false) {
//		switch(�ړI) {
//			case ���:
//				if(�G���R�[�h�^�C�v���������Ă���) {
//					return translate_to_string_engine;
//				} else {
//					return auto_translate_engine;
//				}
//
//			case �o��:
//				return translate_to_binary_engine;
//
//			default:
//				return manual_translate_engine;
//		}
//	}

//	���N���X�K�w�}
//
//			[manual_translate_engine]
//			�@��
//			�@����[translate_to_string_engine]
//			�@���@�@��
//			�@���@�@����[auto_translate_engine]
//			�@��
//			�@����[translate_to_binary_engine]
//


//	�N���X�����o
//		�R���X�g���N�^
//		traslate�n
//		order�n
//	�ȈՊ֐��C���^�[�t�F�C�X

template<class from_string = bbl_default_string, class to_string = bbl_default_string>
class manual_translate_engine :public bbl_translate_engine<from_string, to_string> {
  public:
	typedef manual_translate_engine this_type;
	typedef	bbl_translate_engine<from_string, to_string> base_type;
	typedef typename base_type::bbl_translater_type	bbl_translater_type;
	typedef typename base_type::from_string_type	from_string_type;
	typedef typename base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	bbl_translater_type	engine;
	manual_translate_engine(int from_base_encoding, int to_base_encoding = babel::get_base_encoding())
		:engine(this_type::order(from_base_encoding, to_base_encoding)) {}
#ifdef	__BBL_LARGE_BOM_LOGIC__
	manual_translate_engine(const bbl_translater_type & X_engine)
		:engine(X_engine) {}
#endif	//	__BBL_LARGE_BOM_LOGIC__
  protected:
	void translate() {
		engine.translate(base_type::untranslated_buffer);
//		untranslated_buffer.clear();	//	g++ �́R(�M�D�L)�m�{�P�F�I
		base_type::untranslated_buffer.erase();
		base_type::translated_buffer += engine.pook_buffer();
	}
	void flush() {
		engine.flush();
//		untranslated_buffer.clear();	//	g++ �́R(�M�D�L)�m�{�P�F�I
		base_type::untranslated_buffer.erase();
		base_type::translated_buffer += engine.pook_buffer();
	}
	void clear() {
		base_type::clear();
		engine.clear();
	}
  public:
static bbl_translater_type create(int from_base_encoding, int to_base_encoding = babel::get_base_encoding()) {
		return new this_type(from_base_encoding, to_base_encoding);
	}
//static const to_string_type ignite(
//			const from_string_type &X, int from_base_encoding, int to_base_encoding = babel::get_base_encoding()) {
//		return this_type(from_base_encoding, to_base_encoding).base_type::ignite(X);
//	}
static const to_string_type ignite(const from_string_type &X, int from_base_encoding, int to_base_encoding = babel::get_base_encoding());
static bbl_translater_type order(int from_base_encoding, int to_base_encoding = babel::get_base_encoding());
};

//	specialize �̐�s�錾

template<>
manual_translate_engine<bbl_string, bbl_string>::bbl_translater_type
manual_translate_engine<bbl_string, bbl_string>::order(int X_from_base_encoding, int X_to_base_encoding);

template<>
const bbl_string manual_translate_engine<bbl_string, bbl_string>::ignite(const bbl_string &X, int X_from_base_encoding, int X_to_base_encoding);

#	if	defined(__BBL_USE_UNICODE__)
template<>
manual_translate_engine<bbl_string, bbl_wstring>::bbl_translater_type
manual_translate_engine<bbl_string, bbl_wstring>::order(int X_from_base_encoding, int X_to_base_encoding);

template<>
const bbl_wstring manual_translate_engine<bbl_string, bbl_wstring>::ignite(const bbl_string &X, int X_from_base_encoding, int X_to_base_encoding);

template<>
manual_translate_engine<bbl_wstring, bbl_string>::bbl_translater_type
manual_translate_engine<bbl_wstring, bbl_string>::order(int X_from_base_encoding, int X_to_base_encoding);

template<>
const bbl_string manual_translate_engine<bbl_wstring, bbl_string>::ignite(const bbl_wstring &X, int X_from_base_encoding, int X_to_base_encoding);

template<>
manual_translate_engine<bbl_wstring, bbl_wstring>::bbl_translater_type
manual_translate_engine<bbl_wstring, bbl_wstring>::order(int X_from_base_encoding, int X_to_base_encoding);

template<>
const bbl_wstring manual_translate_engine<bbl_wstring, bbl_wstring>::ignite(const bbl_wstring &X, int X_from_base_encoding, int X_to_base_encoding);
#	endif	//	defined(__BBL_USE_UNICODE__)


template<class string_type = bbl_default_string>
class translate_to_string_engine :public manual_translate_engine<bbl_binary, string_type> {
//
//	���̃N���X�� from_string_type �� bbl_binary �ɌŒ肳��Ă���ȊO�͋@�\�I��
//	manual_translate_engine �ƑS������ł��B
//
//	�E�E�E���̃N���X�ɂ͏����I��BOM�֘A�̏��׍H���{����������܂���B
//
public:
	typedef translate_to_string_engine<string_type> this_type;
	typedef	manual_translate_engine<bbl_binary, string_type> parent_type;
	typedef	bbl_translate_engine<bbl_binary, string_type> base_type;
	typedef typename base_type::bbl_translater_type	bbl_translater_type;
	typedef typename base_type::from_string_type		from_string_type;
	typedef typename base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
#ifdef	__BBL_LARGE_BOM_LOGIC__
	translate_to_string_engine(int from_base_encoding, int to_base_encoding = babel::get_base_encoding())
		:parent_type(this_type::order(from_base_encoding, to_base_encoding)) {}
#else	//	__BBL_LARGE_BOM_LOGIC__
	translate_to_string_engine(int from_base_encoding, int to_base_encoding = babel::get_base_encoding())
		:parent_type(from_base_encoding, to_base_encoding) {}
#endif	//	__BBL_LARGE_BOM_LOGIC__
  protected:
  public:
#ifdef	__BBL_LARGE_BOM_LOGIC__
static bbl_translater_type create(int from_base_encoding, int to_base_encoding = babel::get_base_encoding()) {
		return new this_type(from_base_encoding, to_base_encoding);
	}
static const to_string_type ignite(const from_string_type &X, int from_base_encoding, int to_base_encoding = babel::get_base_encoding());
static bbl_translater_type order(int from_base_encoding, int to_base_encoding = babel::get_base_encoding());
#endif	//	__BBL_LARGE_BOM_LOGIC__
};


template<class to_string = bbl_default_string>
class auto_translate_engine :public translate_to_string_engine<to_string> {
  public:
	typedef auto_translate_engine this_type;
	typedef	translate_to_string_engine<to_string> base_type;
	typedef typename base_type::bbl_translater_type	bbl_translater_type;
	typedef typename base_type::from_string_type		from_string_type;
	typedef typename base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
	int from_base_encoding, to_base_encoding;
	auto_translate_engine(int X_to_base_encoding = babel::get_base_encoding())
		:base_type(X_to_base_encoding, X_to_base_encoding), from_base_encoding(X_to_base_encoding), to_base_encoding(X_to_base_encoding) {}
  protected:
	void translate() {
		int new_from_base_encoding = analyze_base_encoding(base_type::untranslated_buffer);
		if (from_base_encoding != new_from_base_encoding) {
			from_base_encoding = new_from_base_encoding;
			base_type::engine = base_type::order(from_base_encoding, to_base_encoding);
		} else {
//			engine.clear();
		}
		base_type::engine.translate(base_type::untranslated_buffer);
//		untranslated_buffer.clear();	//	g++ �́R(�M�D�L)�m�{�P�F�I
		base_type::untranslated_buffer.erase();
		base_type::translated_buffer = base_type::engine.pook_buffer();
	}
  public:
static bbl_translater_type create(int X_to_base_encoding = babel::get_base_encoding()) {
		return new this_type(X_to_base_encoding);
	}
static const to_string_type ignite(const from_string_type &X, int X_to_base_encoding = babel::get_base_encoding()) {
#if defined(__BORLANDC__)
		//  ���R�͂悭�킩��񂪁��������Ă����Ȃ��� Borland �̃R���p�C���̓g�`�������R�[�h��f���B
		this_type temp(X_to_base_encoding);
		return temp.base_type::ignite(X, analyze_base_encoding(X), X_to_base_encoding);
#else
		return this_type(X_to_base_encoding).base_type::ignite(X, analyze_base_encoding(X), X_to_base_encoding);
#endif
	}
};


template<class from_string = bbl_default_string, class to_string = bbl_default_string>
class manual_translate :public bbl_demi<to_string> {
  public:
	manual_translate(const from_string &X, int from_base_encoding, int to_base_encoding = babel::get_base_encoding())
	:bbl_demi<to_string>(manual_translate_engine<from_string, to_string>::ignite(X, from_base_encoding, to_base_encoding)) { }
};

template<class to_string = bbl_default_string>
class translate_to_string :public bbl_demi<to_string> {
  public:
	translate_to_string(const bbl_binary &X, int from_base_encoding, int to_base_encoding = babel::get_base_encoding())
	:bbl_demi<to_string>(translate_to_string_engine<to_string>::ignite(X, from_base_encoding, to_base_encoding)) { }
};

template<class to_string = bbl_default_string>
class auto_translate :public bbl_demi<to_string> {
  public:
	auto_translate(const bbl_binary &X, int to_base_encoding = babel::get_base_encoding())
	:bbl_demi<to_string>(auto_translate_engine<to_string>::ignite(X, to_base_encoding)) { }
};


template<class string_type = bbl_default_string>
class translate_to_binary_engine :public manual_translate_engine<string_type, bbl_binary> {
//
//	���̃N���X�� to_string_type �� bbl_binary �ɌŒ肳��Ă��邱�Ƃ�
//	from_base_encoding �̃f�t�H���g�l���ݒ肳��Ă��邱�ƈȊO�͋@�\�I��
//	manual_translate_engine �ƑS������ł��B
//
//	�E�E�E���̃N���X�ɂ͏����I��BOM�֘A�̏��׍H���{����������܂���B
//
public:
	typedef translate_to_binary_engine<string_type> this_type;
	typedef	manual_translate_engine<bbl_binary, string_type> parent_type;
	typedef	bbl_translate_engine<bbl_binary, string_type> base_type;
	typedef typename base_type::bbl_translater_type	bbl_translater_type;
	typedef typename base_type::from_string_type		from_string_type;
	typedef typename base_type::to_string_type		to_string_type;
//  private:	//	VC �́R(�M�D�L)�m�A�z�H�I
  protected:
#ifdef	__BBL_LARGE_BOM_LOGIC__
	translate_to_binary_engine(int from_base_encoding = babel::get_base_encoding(), int to_base_encoding = babel::get_base_encoding())
		:parent_type(this_type::order(from_base_encoding, to_base_encoding)) {}
#else	//	__BBL_LARGE_BOM_LOGIC__
	translate_to_binary_engine(int from_base_encoding = babel::get_base_encoding(), int to_base_encoding = babel::get_base_encoding())
		:parent_type(from_base_encoding, to_base_encoding) {}
#endif	//	__BBL_LARGE_BOM_LOGIC__
  protected:
  public:
#ifdef	__BBL_LARGE_BOM_LOGIC__
static bbl_translater_type create(int from_base_encoding, int to_base_encoding = babel::get_base_encoding()) {
		return new this_type(from_base_encoding, to_base_encoding);
	}
static const to_string_type ignite(const from_string_type &X, int from_base_encoding, int to_base_encoding = babel::get_base_encoding());
static bbl_translater_type order(int from_base_encoding, int to_base_encoding = babel::get_base_encoding());
#endif	//	__BBL_LARGE_BOM_LOGIC__
};

inline const bbl_binary translate_to_binary(const bbl_string &X, int X_to_base_encoding, int X_from_base_encoding = babel::get_base_encoding()) {
	return manual_translate_engine<bbl_string, bbl_binary>::ignite(X, X_from_base_encoding, X_to_base_encoding);
}
#	if	defined(__BBL_USE_UNICODE__)
inline const bbl_binary translate_to_binary(const bbl_wstring &X, int X_to_base_encoding, int X_from_base_encoding = babel::base_encoding::unicode) {
	return manual_translate_engine<bbl_wstring, bbl_binary>::ignite(X, X_from_base_encoding, X_to_base_encoding);
}
#	endif	//	defined(__BBL_USE_UNICODE__)
#endif	//	defined(__BBL_USE_SELECTORS__)

/******************************************************************************
	��������                 Trick Library 'dagger'                 ��������
	��������             http://tricklib.com/cxx/dagger/            ��������
******************************************************************************/

}	//	namespace babel

#if defined(__BORLANDC__)
#	pragma warn .8027
#endif

#endif	//	__BABEL_BBL_H__

/******************************************************************************
	��������                  Wraith the Trickster                  ��������
	�������� �`I'll go with heaven's advantage and fool's wisdom.�` ��������
******************************************************************************/

