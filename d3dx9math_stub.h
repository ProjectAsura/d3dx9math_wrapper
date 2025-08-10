//-----------------------------------------------------------------------------
// File : d3dx9math_stub.h
// Desc : Stub for d3dx9math
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <cstring> // for memcpy.
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

// 既にインクルード済みかチェック.
#ifdef __D3DX9MATH_H__
#error "d3dx9math.h Already Included."
#endif//__D3DX9MATH_H__

#ifdef __D3DX9MATH_INL__
#error "d3dx9math.inl Already Included."
#endif//__D3DX9MATH_INL__

// バッティングしないようにインクルードガードを定義しておく.
#ifndef __D3DX9MATH_H__
#define __D3DX9MATH_H__
#endif//__D3DX9MATH_H__

#ifndef __D3DX9MATH_INL__
#define __D3DX9MATH_INL__
#endif//__D3DX9MATH_INL__

// Wrapper API用の呼び出し規約.
#ifndef WRAP_API
#define WRAP_API
#endif//WRAP_API

#define D3DX_PI     DirectX::XM_PI
#define D3DX_1BYPI  DirectX::XM_1DIVPI


#ifndef D3DVECTOR_DEFINED
typedef struct _D3DVECTOR
{
    float x;
    float y;
    float z;
} D3DVECTOR;
#define D3DVECTOR_DEFINED
#endif

#ifndef D3DCOLORVALUE_DEFINED
typedef struct _D3DCOLORVALUE
{
    float r;
    float g;
    float b;
    float a;
} D3DCOLORVALUE;
#define D3DCOLORVALUE_DEFINED
#endif

#ifndef D3DMATRIX_DEFINED
typedef struct _D3DMATRIX
{
    union
    {
        struct
        {
            float        _11, _12, _13, _14;
            float        _21, _22, _23, _24;
            float        _31, _32, _33, _34;
            float        _41, _42, _43, _44;
        };
        float m[4][4];
    };
} D3DMATRIX;
#define D3DMATRIX_DEFINED
#endif

typedef struct _D3DVIEWPORT9
{
    uint32_t    X;
    uint32_t    Y;
    uint32_t    Width;
    uint32_t    Height;
    float       MinZ;
    float       MaxZ;
} D3DVIEWPORT9;

inline float D3DXToRadian(float degree)
{ return DirectX::XMConvertToRadians(degree); }

inline float D3DXToDegree(float radian)
{ return DirectX::XMConvertToDegrees(radian); }

struct D3DXFLOAT16;

//--------------------------
// Float16
//--------------------------

// Converts an array 32-bit floats to 16-bit floats
D3DXFLOAT16* WRAP_API D3DXFloat32To16Array(D3DXFLOAT16 *pOut, const float *pIn, uint32_t n);

// Converts an array 16-bit floats to 32-bit floats
float* WRAP_API D3DXFloat16To32Array(float *pOut, const D3DXFLOAT16 *pIn, uint32_t n);


///////////////////////////////////////////////////////////////////////////////
// D3DXFLOAT16 structure
///////////////////////////////////////////////////////////////////////////////
struct D3DXFLOAT16
{
public:
    D3DXFLOAT16()
    { /* DO_NOTHING */ }

    D3DXFLOAT16(float f)
    { value = DirectX::PackedVector::XMConvertFloatToHalf(f); }

    D3DXFLOAT16(const D3DXFLOAT16& f)
    { value = f.value; }

    operator float () const
    { return DirectX::PackedVector::XMConvertHalfToFloat(value); }

    bool operator == (const D3DXFLOAT16& other) const
    { return value == other.value; }

    bool operator != (const D3DXFLOAT16& other) const
    { return value != other.value; }

protected:
    uint16_t value = 0;
};

///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR2 structure
///////////////////////////////////////////////////////////////////////////////
struct D3DXVECTOR2 : public DirectX::XMFLOAT2
{
public:
    D3DXVECTOR2()
    { /* DO_NOTHING */ }

    D3DXVECTOR2(const float* pf)
    {
        assert(pf != nullptr);
        x = pf[0];
        y = pf[1];
    }

    D3DXVECTOR2(const D3DXFLOAT16* pf)
    {
        assert(pf != nullptr);
        D3DXFloat16To32Array(&x, pf, 2);
    }

    D3DXVECTOR2(float fx, float fy)
    {
        x = fx;
        y = fy;
    }

    operator float* ()
    { return &x; }

    operator const float* () const
    { return &x; }

    D3DXVECTOR2& operator += (const D3DXVECTOR2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    D3DXVECTOR2& operator -= (const D3DXVECTOR2& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    D3DXVECTOR2& operator *= (float f)
    {
        x *= f;
        y *= f;
        return *this;
    }

    D3DXVECTOR2& operator /= (float f)
    {
        auto inv = 1.0f / f;
        x *= inv;
        y *= inv;
        return *this;
    }

    D3DXVECTOR2 operator + () const
    { return *this; }

    D3DXVECTOR2 operator - () const
    { return D3DXVECTOR2(-x, -y); }

    D3DXVECTOR2 operator + (const D3DXVECTOR2& v) const
    { return D3DXVECTOR2(x + v.x, y + v.y); }

    D3DXVECTOR2 operator - (const D3DXVECTOR2& v) const
    { return D3DXVECTOR2(x - v.x, y - v.y); }

    D3DXVECTOR2 operator * (float f) const
    { return D3DXVECTOR2(x * f, y * f); }

    D3DXVECTOR2 operator / (float f) const
    {
        auto inv = 1.0f / f;
        return D3DXVECTOR2(x * inv, y * inv); 
    }

    friend D3DXVECTOR2 operator * (float f, const D3DXVECTOR2& v)
    { return D3DXVECTOR2(f * v.x, f * v.y); }

    bool operator == (const D3DXVECTOR2& v) const
    { return x == v.x && y == v.y; }

    bool operator != (const D3DXVECTOR2& v) const
    { return x != v.x && y != v.y; }
};

///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR2_16F structure
///////////////////////////////////////////////////////////////////////////////
struct D3DXVECTOR2_16F
{
public:
    D3DXFLOAT16 x;
    D3DXFLOAT16 y;

    D3DXVECTOR2_16F()
    { /* DO_NOTHING */ }

    D3DXVECTOR2_16F(const float* pf)
    {
        assert(pf != nullptr);
        x = DirectX::PackedVector::XMConvertFloatToHalf(pf[0]);
        y = DirectX::PackedVector::XMConvertFloatToHalf(pf[1]);
    }

    D3DXVECTOR2_16F(const D3DXFLOAT16 * pf)
    {
        assert(pf != nullptr);
        x = pf[0];
        y = pf[1];
    }

    D3DXVECTOR2_16F(const D3DXFLOAT16 &fx, const D3DXFLOAT16 &fy)
    {
        x = fx;
        y = fy;
    }

    operator D3DXFLOAT16* ()
    { return &x; }

    operator const D3DXFLOAT16* () const
    { return &x; }

    bool operator == (const D3DXVECTOR2_16F& v) const
    { return x == v.x && y == v.y; }
  
    bool operator != (const D3DXVECTOR2_16F& v) const
    { return x != v.x || y != v.y; }
};


///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR3 structure
///////////////////////////////////////////////////////////////////////////////
struct D3DXVECTOR3 : public DirectX::XMFLOAT3
{
public:
    D3DXVECTOR3()
    { /* DO_NOTHING */ }

    D3DXVECTOR3(const float * pf)
    {
        assert(pf != nullptr);
        x = pf[0];
        y = pf[1];
        z = pf[2];
    }

    D3DXVECTOR3(const D3DVECTOR& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
    }

    D3DXVECTOR3(const D3DXFLOAT16 * pf)
    {
        assert(pf != nullptr);
        D3DXFloat16To32Array(&x, pf, 3);
    }

    D3DXVECTOR3(float fx, float fy, float fz)
    {
        x = fx;
        y = fy;
        z = fz;
    }

    operator float* ()
    { return &x; }

    operator const float* () const
    { return &x; }

    D3DXVECTOR3& operator += (const D3DXVECTOR3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    D3DXVECTOR3& operator -= (const D3DXVECTOR3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    D3DXVECTOR3& operator *= (float f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }

    D3DXVECTOR3& operator /= (float f)
    {
        auto inv = 1.0f / f;
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }

    D3DXVECTOR3 operator + () const
    { return *this; }

    D3DXVECTOR3 operator - () const
    { return D3DXVECTOR3(-x, -y, -z); }

    D3DXVECTOR3 operator + (const D3DXVECTOR3& v) const
    { return D3DXVECTOR3(x + v.x, y + v.y, z + v.z); }

    D3DXVECTOR3 operator - (const D3DXVECTOR3& v) const
    { return D3DXVECTOR3(x - v.x, y - v.y, z - v.z); }

    D3DXVECTOR3 operator * (float f) const
    { return D3DXVECTOR3(x * f, y * f, z * f); }

    D3DXVECTOR3 operator / (float f) const
    {
        auto inv = 1.0f / f;
        return D3DXVECTOR3(x * inv, y * inv, z * inv);
    }

    friend D3DXVECTOR3 operator * (float f, const struct D3DXVECTOR3& v)
    { return D3DXVECTOR3(f * v.x, f * v.y, f * v.z); }

    bool operator == (const D3DXVECTOR3& v) const
    { return x == v.x && y == v.y && z == v.z; }

    bool operator != (const D3DXVECTOR3& v) const
    { return x != v.x || y != v.y || z != v.z; }
};

///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR3_16F structure
///////////////////////////////////////////////////////////////////////////////
struct D3DXVECTOR3_16F
{
public:
    D3DXFLOAT16 x;
    D3DXFLOAT16 y;
    D3DXFLOAT16 z;

    D3DXVECTOR3_16F()
    { /* DO_NOTHING */ }

    D3DXVECTOR3_16F(const float* pf)
    {
        assert(pf != nullptr);
        x = DirectX::PackedVector::XMConvertFloatToHalf(pf[0]);
        y = DirectX::PackedVector::XMConvertFloatToHalf(pf[1]);
        z = DirectX::PackedVector::XMConvertFloatToHalf(pf[2]);
    }

    D3DXVECTOR3_16F(const D3DVECTOR& v)
    {
        x = DirectX::PackedVector::XMConvertFloatToHalf(v.x);
        y = DirectX::PackedVector::XMConvertFloatToHalf(v.y);
        z = DirectX::PackedVector::XMConvertFloatToHalf(v.z);
    }

    D3DXVECTOR3_16F(const D3DXFLOAT16 * pf)
    {
        assert(pf != nullptr);
        x = pf[0];
        y = pf[1];
        z = pf[2];
    }
    D3DXVECTOR3_16F(const D3DXFLOAT16 &fx, const D3DXFLOAT16 &fy, const D3DXFLOAT16 &fz)
    {
        x = fx;
        y = fy;
        z = fz;
    }

    operator D3DXFLOAT16* ()
    { return &x; }

    operator const D3DXFLOAT16* () const
    { return &x; }

    bool operator == (const D3DXVECTOR3_16F& v) const
    { return x == v.x && y == v.y && z == v.z; }

    bool operator != (const D3DXVECTOR3_16F& v) const
    { return x != v.x || y != v.y || z != v.z; }
};

///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR4 structure
///////////////////////////////////////////////////////////////////////////////
struct D3DXVECTOR4 : public DirectX::XMFLOAT4
{
public:
    D3DXVECTOR4() 
    { /* DO_NOTHING */ }

    D3DXVECTOR4(const float* pf)
    {
        assert(pf != nullptr);
        x = pf[0];
        y = pf[1];
        z = pf[2];
    }

    D3DXVECTOR4(const D3DXFLOAT16* pf)
    {
        assert(pf != nullptr);
        D3DXFloat16To32Array(&x, pf, 4);
    }

    D3DXVECTOR4(const D3DVECTOR& v, float f)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = f;
    }

    D3DXVECTOR4(float fx, float fy, float fz, float fw)
    {
        x = fx;
        y = fy;
        z = fz;
        w = fw;
    }

    operator float* ()
    { return &x; }

    operator const float* () const
    { return &x; }

    D3DXVECTOR4& operator += (const D3DXVECTOR4& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }

    D3DXVECTOR4& operator -= (const D3DXVECTOR4& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return *this;
    }

    D3DXVECTOR4& operator *= (float f)
    {
        x *= f;
        y *= f;
        z *= f;
        w *= f;
        return *this;
    }

    D3DXVECTOR4& operator /= (float f)
    {
        auto inv = 1.0f / f;
        x *= inv;
        y *= inv;
        z *= inv;
        w *= inv;
        return *this;
    }

    D3DXVECTOR4 operator + () const
    { return *this; }

    D3DXVECTOR4 operator - () const
    { return D3DXVECTOR4(-x, -y, -z, -w); }

    D3DXVECTOR4 operator + (const D3DXVECTOR4& v) const
    { return D3DXVECTOR4(x + v.x, y + v.y, z + v.z, w + v.w); }

    D3DXVECTOR4 operator - (const D3DXVECTOR4& v) const
    { return D3DXVECTOR4(x - v.y, y - v.y, z - v.z, w - v.w); }

    D3DXVECTOR4 operator * (float f) const
    { return D3DXVECTOR4(x * f, y * f, z * f, w * f); }

    D3DXVECTOR4 operator / (float f) const
    {
        auto inv = 1.0f / f;
        return D3DXVECTOR4(x * inv, y * inv, z * inv, w * inv);
    }

    friend D3DXVECTOR4 operator * (float f, const D3DXVECTOR4& v)
    { return D3DXVECTOR4(f * v.x, f * v.y, f * v.z, f * v.w); }

    bool operator == (const D3DXVECTOR4& v) const
    { return x == v.x && y == v.y && z == v.z && w == v.w; }

    bool operator != (const D3DXVECTOR4& v) const
    { return x != v.x || y != v.y || z != v.z || w != v.w; }
};

///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR4_16F structure
///////////////////////////////////////////////////////////////////////////////
struct D3DXVECTOR4_16F
{
public:
    D3DXFLOAT16 x;
    D3DXFLOAT16 y;
    D3DXFLOAT16 z;
    D3DXFLOAT16 w;

    D3DXVECTOR4_16F()
    { /* DO_NOTHING */ }

    D3DXVECTOR4_16F(const float * pf)
    {
        assert(pf != nullptr);
        D3DXFloat32To16Array(&x, pf, 4);
    }

    D3DXVECTOR4_16F(const D3DXFLOAT16* pf)
    {
        assert(pf != nullptr);
        x = pf[0];
        y = pf[1];
        z = pf[2];
        w = pf[3];
    }

    D3DXVECTOR4_16F(const D3DXVECTOR3_16F& v, const D3DXFLOAT16& f)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = f;
    }

    D3DXVECTOR4_16F(const D3DXFLOAT16& fx, const D3DXFLOAT16& fy, const D3DXFLOAT16& fz, const D3DXFLOAT16& fw)
    {
        x = fx;
        y = fy;
        z = fz;
        w = fw;
    }

    operator D3DXFLOAT16* ()
    { return &x; }

    operator const D3DXFLOAT16* () const
    { return &x; }

    bool operator == ( const D3DXVECTOR4_16F& v) const
    { return x == v.x && y == v.y && z == v.z && w == v.w; }

    bool operator != ( const D3DXVECTOR4_16F& v) const
    { return x != v.x || y != v.y || z != v.z || w != v.w; }
};

///////////////////////////////////////////////////////////////////////////////
// D3DXMATRIX structure
///////////////////////////////////////////////////////////////////////////////
struct D3DXMATRIX : public DirectX::XMFLOAT4X4
{
public:
    D3DXMATRIX()
    { /* DO_NOTHING */ }

    D3DXMATRIX( const float * pf)
    {
        assert(pf != nullptr);
        memcpy(&_11, pf, sizeof(D3DXMATRIX));
    }

    D3DXMATRIX( const D3DMATRIX& mat)
    { memcpy(&_11, &mat, sizeof(D3DXMATRIX)); }

    D3DXMATRIX(const D3DXFLOAT16* pf)
    {
        assert(pf != nullptr);
        D3DXFloat16To32Array(&_11, pf, 16);
    }

    D3DXMATRIX(float f11, float f12, float f13, float f14,
               float f21, float f22, float f23, float f24,
               float f31, float f32, float f33, float f34,
               float f41, float f42, float f43, float f44)
    {
        _11 = f11; _12 = f12; _13 = f13; _14 = f14;
        _21 = f21; _22 = f22; _23 = f23; _24 = f24;
        _31 = f31; _32 = f32; _33 = f33; _34 = f34;
        _41 = f41; _42 = f42; _43 = f43; _44 = f44;
    }


    float& operator () (uint32_t row, uint32_t col)
    { return m[row][col]; }

    float  operator () (uint32_t row, uint32_t col) const
    { return m[row][col]; }

    operator float* ()
    { return &_11; }

    operator const float* () const
    { return &_11; }

    D3DXMATRIX& operator *= (const D3DXMATRIX& mat)
    {
        auto m1  = DirectX::XMLoadFloat4x4(this);
        auto m2  = DirectX::XMLoadFloat4x4(&mat);
        auto ret = DirectX::XMMatrixMultiply(m1, m2);
        DirectX::XMStoreFloat4x4(this, ret);
        return *this;
    }

    D3DXMATRIX& operator += (const D3DXMATRIX& mat)
    {
        _11 += mat._11; _12 += mat._12; _13 += mat._13; _14 += mat._14;
        _21 += mat._21; _22 += mat._22; _23 += mat._23; _24 += mat._24;
        _31 += mat._31; _32 += mat._32; _33 += mat._33; _34 += mat._34;
        _41 += mat._41; _42 += mat._42; _43 += mat._43; _44 += mat._44;
        return *this;
    }

    D3DXMATRIX& operator -= (const D3DXMATRIX& mat)
    {
        _11 -= mat._11; _12 -= mat._12; _13 -= mat._13; _14 -= mat._14;
        _21 -= mat._21; _22 -= mat._22; _23 -= mat._23; _24 -= mat._24;
        _31 -= mat._31; _32 -= mat._32; _33 -= mat._33; _34 -= mat._34;
        _41 -= mat._41; _42 -= mat._42; _43 -= mat._43; _44 -= mat._44;
        return *this;
    }

    D3DXMATRIX& operator *= (float f)
    {
        _11 *= f; _12 *= f; _13 *= f; _14 *= f;
        _21 *= f; _22 *= f; _23 *= f; _24 *= f;
        _31 *= f; _32 *= f; _33 *= f; _34 *= f;
        _41 *= f; _42 *= f; _43 *= f; _44 *= f;
        return *this;
    }

    D3DXMATRIX& operator /= (float f)
    {
        auto inv = 1.0f / f;
        _11 *= inv; _12 *= inv; _13 *= inv; _14 *= inv;
        _21 *= inv; _22 *= inv; _23 *= inv; _24 *= inv;
        _31 *= inv; _32 *= inv; _33 *= inv; _34 *= inv;
        _41 *= inv; _42 *= inv; _43 *= inv; _44 *= inv;
        return *this;
    }

    D3DXMATRIX operator + () const
    { return *this; }

    D3DXMATRIX operator - () const
    {
        return D3DXMATRIX(-_11, -_12, -_13, -_14,
                          -_21, -_22, -_23, -_24,
                          -_31, -_32, -_33, -_34,
                          -_41, -_42, -_43, -_44);
    }

    D3DXMATRIX operator * (const D3DXMATRIX& mat) const
    {
        auto m1  = DirectX::XMLoadFloat4x4(this);
        auto m2  = DirectX::XMLoadFloat4x4(&mat);
        auto ret = DirectX::XMMatrixMultiply(m1, m2);

        D3DXMATRIX out;
        DirectX::XMStoreFloat4x4(&out, ret);
        return out;
    }

    D3DXMATRIX operator + (const D3DXMATRIX& mat) const
    {
        return D3DXMATRIX(
            _11 + mat._11, _12 + mat._12, _13 + mat._13, _14 + mat._14,
            _21 + mat._21, _22 + mat._22, _23 + mat._23, _24 + mat._24,
            _31 + mat._31, _32 + mat._32, _33 + mat._33, _34 + mat._34,
            _41 + mat._41, _42 + mat._42, _43 + mat._43, _44 + mat._44);
    }

    D3DXMATRIX operator - (const D3DXMATRIX& mat) const
    {
        return D3DXMATRIX(
            _11 - mat._11, _12 - mat._12, _13 - mat._13, _14 - mat._14,
            _21 - mat._21, _22 - mat._22, _23 - mat._23, _24 - mat._24,
            _31 - mat._31, _32 - mat._32, _33 - mat._33, _34 - mat._34,
            _41 - mat._41, _42 - mat._42, _43 - mat._43, _44 - mat._44);
    }

    D3DXMATRIX operator * (float f) const
    {
        return D3DXMATRIX(
            _11 * f, _12 * f, _13 * f, _14 * f,
            _21 * f, _22 * f, _23 * f, _24 * f,
            _31 * f, _32 * f, _33 * f, _34 * f,
            _41 * f, _42 * f, _43 * f, _44 * f);
    }

    D3DXMATRIX operator / (float f) const
    {
        auto inv = 1.0f / f;
        return D3DXMATRIX(
            _11 * inv, _12 * inv, _13 * inv, _14 * inv,
            _21 * inv, _22 * inv, _23 * inv, _24 * inv,
            _31 * inv, _32 * inv, _33 * inv, _34 * inv,
            _41 * inv, _42 * inv, _43 * inv, _44 * inv);
    }

    friend D3DXMATRIX operator * (float f, const D3DXMATRIX& mat )
    {
        return D3DXMATRIX(
            f * mat._11, f * mat._12, f * mat._13, f * mat._14,
            f * mat._21, f * mat._22, f * mat._23, f * mat._24,
            f * mat._31, f * mat._32, f * mat._33, f * mat._34,
            f * mat._41, f * mat._42, f * mat._43, f * mat._44);
    }

    bool operator == (const D3DXMATRIX& mat) const
    { return 0 == memcmp(this, &mat, sizeof(D3DXMATRIX)); }

    bool operator != (const D3DXMATRIX& mat) const
    { return 0 != memcmp(this, &mat, sizeof(D3DXMATRIX)); }
};

///////////////////////////////////////////////////////////////////////////////
// D3DXMATRIXA16 structure
///////////////////////////////////////////////////////////////////////////////
struct D3DXMATRIXA16 : public D3DXMATRIX
{
    D3DXMATRIXA16() 
    { /* DO_NOTHING */ }

    D3DXMATRIXA16(const float* pf)
    : D3DXMATRIX(pf)
    { /* DO_NOTHING */ }

    D3DXMATRIXA16(const D3DMATRIX& m)
    : D3DXMATRIX(m)
    { /* DO_NOTHING */ }

    D3DXMATRIXA16(const D3DXFLOAT16* pf)
    : D3DXMATRIX(pf)
    { /* DO_NOTHING */ }

    D3DXMATRIXA16(float f11, float f12, float f13, float f14,
                  float f21, float f22, float f23, float f24,
                  float f31, float f32, float f33, float f34,
                  float f41, float f42, float f43, float f44)
    : D3DXMATRIX(
        f11, f12, f13, f14,
        f21, f22, f23, f24,
        f31, f32, f33, f34,
        f41, f42, f43, f44)
    { /* DO_NOTHING */ }
    
    // assignment operators
    D3DXMATRIXA16& operator = (const D3DXMATRIX& rhs)
    {
        memcpy(&_11, &rhs, sizeof(D3DXMATRIX));
        return *this;
    }
};

///////////////////////////////////////////////////////////////////////////////
// D3DXQUATERNION structure
///////////////////////////////////////////////////////////////////////////////
struct D3DXQUATERNION : public DirectX::XMFLOAT4
{
public:
    D3DXQUATERNION() 
    { /* DO_NOTHING */ }

    D3DXQUATERNION(const float* pf)
    {
        assert(pf != nullptr);
        x = pf[0];
        y = pf[1];
        z = pf[2];
        w = pf[3];
    }

    D3DXQUATERNION(const D3DXFLOAT16* pf)
    {
        assert(pf != nullptr);
        D3DXFloat16To32Array(&x, pf, 4);
    }

    D3DXQUATERNION(float fx, float fy, float fz, float fw )
    {
        x = fx;
        y = fy;
        z = fz;
        w = fw;
    }

    operator float* ()
    { return &x; }

    operator const float* () const
    { return &x; }

    D3DXQUATERNION& operator += (const D3DXQUATERNION& q)
    {
        x += q.x;
        y += q.y;
        z += q.z;
        w += q.w;
        return *this;
    }

    D3DXQUATERNION& operator -= (const D3DXQUATERNION& q)
    {
        x -= q.x;
        y -= q.y;
        z -= q.z;
        w -= q.w;
        return *this;
    }

    D3DXQUATERNION& operator *= (const D3DXQUATERNION& q)
    {
        auto q1  = DirectX::XMLoadFloat4(this);
        auto q2  = DirectX::XMLoadFloat4(&q);
        auto ret = DirectX::XMQuaternionMultiply(q1, q2);
        DirectX::XMStoreFloat4(this, ret);
        return *this;
    }

    D3DXQUATERNION& operator *= (float f)
    {
        x *= f;
        y *= f;
        z *= f;
        w *= f;
        return *this;
    }

    D3DXQUATERNION& operator /= (float f)
    {
        auto inv = 1.0f / f;
        x *= inv;
        y *= inv;
        z *= inv;
        w *= inv;
        return *this;
    }

    D3DXQUATERNION  operator + () const
    { return *this; }

    D3DXQUATERNION  operator - () const
    { return D3DXQUATERNION(-x, -y, -z, -w); }

    D3DXQUATERNION operator + (const D3DXQUATERNION& q) const
    { return D3DXQUATERNION(x + q.x, y + q.y, z + q.z, w + q.w); }

    D3DXQUATERNION operator - (const D3DXQUATERNION& q) const
    { return D3DXQUATERNION(x - q.x, y - q.y, z - q.z, w - q.w); }

    D3DXQUATERNION operator * (const D3DXQUATERNION& q) const
    {
        auto q1 = DirectX::XMLoadFloat4(this);
        auto q2 = DirectX::XMLoadFloat4(&q);
        auto ret = DirectX::XMQuaternionMultiply(q1, q2);
        D3DXQUATERNION out;
        DirectX::XMStoreFloat4(&out, ret);
        return out;
    }
    D3DXQUATERNION operator * (float f) const
    { return D3DXQUATERNION(x * f, y * f, z * f, w * f); }

    D3DXQUATERNION operator / (float f) const
    {
        auto inv = 1.0f / f;
        return D3DXQUATERNION(x * inv, y * inv, z * inv, w * inv);
    }

    friend D3DXQUATERNION operator * (float f, const D3DXQUATERNION& q)
    { return D3DXQUATERNION(f * q.x, f * q.y, f * q.z, f * q.w); }

    bool operator == ( const D3DXQUATERNION& q) const
    { return x == q.x && y == q.y && z == q.z && w == q.w; }

    bool operator != ( const D3DXQUATERNION& q) const
    { return x != q.x || y != q.y || z != q.z || w != q.w; }
};


///////////////////////////////////////////////////////////////////////////////
// D3DXPLANE structure
///////////////////////////////////////////////////////////////////////////////
struct D3DXPLANE
{
public:
    float a = 0.0f;
    float b = 0.0f;
    float c = 0.0f;
    float d = 0.0f;

    D3DXPLANE()
    { /* DO_NOTHING */ }

    D3DXPLANE(const float* pf)
    {
        assert(pf != nullptr);
        a = pf[0];
        b = pf[1];
        c = pf[2];
        d = pf[3];
    }

    D3DXPLANE(const D3DXFLOAT16* pf)
    {
        assert(pf != nullptr);
        D3DXFloat16To32Array(&a, pf, 4);
    }

    D3DXPLANE(float fa, float fb, float fc, float fd)
    {
        a = fa;
        b = fb;
        c = fc;
        d = fd;
    }

    operator float* ()
    { return &a; }

    operator const float* () const
    { return &a; }

    D3DXPLANE& operator *= (float f)
    {
        a *= f;
        b *= f;
        c *= f;
        d *= d;
        return *this;
    }

    D3DXPLANE& operator /= (float f)
    {
        auto inv = 1.0f / f;
        a *= inv;
        b *= inv;
        c *= inv;
        d *= inv;
        return *this;
    }

    D3DXPLANE operator + () const
    { return *this; }

    D3DXPLANE operator - () const
    { return D3DXPLANE(-a, -b, -c, -d); }

    D3DXPLANE operator * (float f) const
    { return D3DXPLANE(a * f, b * f, c * f, d * f); }

    D3DXPLANE operator / (float f) const
    {
        auto inv = 1.0f / f;
        return D3DXPLANE(a * inv, b * inv, c * inv, d * inv);
    }

    friend D3DXPLANE operator * (float f, const D3DXPLANE& p)
    { return D3DXPLANE(f * p.a, f * p.b, f * p.c, f * p.d); }

    bool operator == (const D3DXPLANE& p) const
    { return a == p.a && b == p.b && c == p.c && d == p.d; }

    bool operator != (const D3DXPLANE& p) const
    { return a != p.a || b != p.b || c != p.c || d != p.d; }

    operator DirectX::XMFLOAT4* ()
    { return reinterpret_cast<DirectX::XMFLOAT4*>(&a); }

    operator const DirectX::XMFLOAT4* () const 
    { return reinterpret_cast<const DirectX::XMFLOAT4*>(&a); }
};

///////////////////////////////////////////////////////////////////////////////
// D3DXCOLOR strcture
///////////////////////////////////////////////////////////////////////////////
struct D3DXCOLOR
{
public:
    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;
    float a = 0.0f;
  
    D3DXCOLOR()
    { /* DO_NOTHING */ }

    D3DXCOLOR(uint32_t dw)
    {
        const float f = 1.0f / 255.0f;
        r = f * (float) uint8_t(dw >> 16);
        g = f * (float) uint8_t(dw >>  8);
        b = f * (float) uint8_t(dw >>  0);
        a = f * (float) uint8_t(dw >> 24);
    }

    D3DXCOLOR(const float* pf)
    {
        assert(pf != nullptr);
        r = pf[0];
        g = pf[1];
        b = pf[2];
    }

    D3DXCOLOR(const D3DXFLOAT16 * pf)
    {
        assert(pf != nullptr);
        D3DXFloat16To32Array(&r, pf, 4);
    }

    D3DXCOLOR(const D3DCOLORVALUE& c)
    {
        r = c.r;
        g = c.g;
        b = c.b;
        a = c.a;
    }

    D3DXCOLOR(float fr, float fg, float fb, float fa)
    {
        r = fr;
        g = fg;
        b = fb;
        a = fa;
    }

    operator uint32_t () const
    {
        uint32_t dwR = (r >= 1.0f) ? 0xff : ((r <= 0.0f) ? 0x00 : uint32_t(r * 255.0f + 0.5f));
        uint32_t dwG = (g >= 1.0f) ? 0xff : ((g <= 0.0f) ? 0x00 : uint32_t(g * 255.0f + 0.5f));
        uint32_t dwB = (b >= 1.0f) ? 0xff : ((b <= 0.0f) ? 0x00 : uint32_t(b * 255.0f + 0.5f));
        uint32_t dwA = (a >= 1.0f) ? 0xff : ((a <= 0.0f) ? 0x00 : uint32_t(a * 255.0f + 0.5f));

        return (dwA << 24) | (dwR << 16) | (dwG << 8) | dwB;
    }

    operator float* ()
    { return &r; }

    operator const float* () const
    { return &r; }

    operator D3DCOLORVALUE* ()
    { return (D3DCOLORVALUE*)&r; }

    operator const D3DCOLORVALUE* () const
    { return (const D3DCOLORVALUE*)&r; }

    operator D3DCOLORVALUE& ()
    { return *(D3DCOLORVALUE*)&r; }

    operator const D3DCOLORVALUE& () const
    { return *(const D3DCOLORVALUE*)&r; }

    D3DXCOLOR& operator += (const D3DXCOLOR& c)
    {
        r += c.r;
        g += c.g;
        b += c.b;
        a += c.a;
        return *this;
    }

    D3DXCOLOR& operator -= (const D3DXCOLOR& c)
    {
        r -= c.r;
        g -= c.g;
        b -= c.b;
        a -= c.a;
        return *this;
    }

    D3DXCOLOR& operator *= (float f)
    {
        r *= f;
        g *= f;
        b *= f;
        a *= f;
        return *this;
    }

    D3DXCOLOR& operator /= (float f)
    {
        auto inv = 1.0f / f;
        r *= inv;
        g *= inv;
        b *= inv;
        a *= inv;
        return *this;
    }

    D3DXCOLOR operator + () const
    { return *this; }

    D3DXCOLOR operator - () const
    { return D3DXCOLOR(-r, -g, -b, -a); }

    D3DXCOLOR operator + (const D3DXCOLOR& c) const
    { return D3DXCOLOR(r + c.r, g + c.g, b + c.b, a + c.a); }

    D3DXCOLOR operator - (const D3DXCOLOR& c) const
    { return D3DXCOLOR(r - c.r, g - c.g, b - c.b, a - c.a); }

    D3DXCOLOR operator * (float f) const
    { return D3DXCOLOR(r * f, g * f, b * f, a * f); }

    D3DXCOLOR operator / (float f) const
    {
        auto inv = 1.0f / f;
        return D3DXCOLOR(r * inv, g * inv, b * inv, a * inv);
    }

    friend D3DXCOLOR operator * (float f, const D3DXCOLOR& c)
    { return D3DXCOLOR(f * c.r, f * c.g, f * c.b, f * c.a); }

    bool operator == (const D3DXCOLOR& c) const
    { return r == c.r && g == c.g && b == c.b && a == c.a; }

    bool operator != (const D3DXCOLOR& c) const
    { return r != c.r || g != c.g || b != c.b || a != c.a; }

    operator DirectX::XMFLOAT4* ()
    { return reinterpret_cast<DirectX::XMFLOAT4*>(&r); }

    operator const DirectX::XMFLOAT4* () const
    { return reinterpret_cast<const DirectX::XMFLOAT4*>(&r); }
};


using LPD3DXVECTOR2     = D3DXVECTOR2*;
using LPD3DXVECTOR3     = D3DXVECTOR3*;
using LPD3DXVECTOR4     = D3DXVECTOR4*;
using LPD3DXVECTOR2_16F = D3DXVECTOR2_16F*;
using LPD3DXVECTOR3_16F = D3DXVECTOR3_16F*;
using LPD3DXVECTOR4_16F = D3DXVECTOR4_16F*;
using LPD3DXMATRIX      = D3DXMATRIX*;
using LPD3DXMATRIXA16   = D3DXMATRIXA16*;
using LPD3DXQUATERNION  = D3DXQUATERNION*;
using LPD3DXPLANE       = D3DXPLANE*;
using LPD3DXCOLOR       = D3DXCOLOR*;


///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR2
///////////////////////////////////////////////////////////////////////////////

inline float D3DXVec2Length(const D3DXVECTOR2 *pV)
{
    assert(pV != nullptr);
    return sqrtf(pV->x * pV->x + pV->y * pV->y);
}

inline float D3DXVec2LengthSq(const D3DXVECTOR2 *pV)
{
    assert(pV != nullptr);
    return pV->x * pV->x + pV->y * pV->y;
}

inline float D3DXVec2Dot(const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2)
{
    assert(pV1 != nullptr);
    assert(pV2 != nullptr);
    return pV1->x * pV2->x + pV1->y * pV2->y;
}

// Z component of ((x1,y1,0) cross (x2,y2,0))
inline float D3DXVec2CCW(const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2)
{
    assert(pV1 != nullptr);
    assert(pV2 != nullptr);
    return pV1->x * pV2->y - pV1->y * pV2->x;
}

inline D3DXVECTOR2* D3DXVec2Add(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = pV1->x + pV2->x;
    pOut->y = pV1->y + pV2->y;
    return pOut;
}

inline D3DXVECTOR2* D3DXVec2Subtract(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = pV1->x - pV2->x;
    pOut->y = pV1->y - pV2->y;
    return pOut;
}

// Minimize each component.  x = min(x1, x2), y = min(y1, y2)
inline D3DXVECTOR2* D3DXVec2Minimize(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = (pV1->x < pV2->x) ? pV1->x : pV2->x;
    pOut->y = (pV1->y < pV2->y) ? pV1->y : pV2->y;
    return pOut;
}

// Maximize each component.  x = max(x1, x2), y = max(y1, y2)
inline D3DXVECTOR2* D3DXVec2Maximize(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = (pV1->x > pV2->x) ? pV1->x : pV2->x;
    pOut->y = (pV1->y > pV2->y) ? pV1->y : pV2->y;
    return pOut;
}

inline D3DXVECTOR2* D3DXVec2Scale(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV, float s)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    pOut->x = pV->x * s;
    pOut->y = pV->y * s;
    return pOut;
}

// Linear interpolation. V1 + s(V2-V1)
inline D3DXVECTOR2* D3DXVec2Lerp(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2, float s)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = pV1->x + s * (pV2->x - pV1->x);
    pOut->y = pV1->y + s * (pV2->y - pV1->y);
    return pOut;
}

D3DXVECTOR2* WRAP_API D3DXVec2Normalize(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV);

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR2* WRAP_API D3DXVec2Hermite(
    D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pT1,
    const D3DXVECTOR2 *pV2, const D3DXVECTOR2 *pT2, float s );

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR2* WRAP_API D3DXVec2CatmullRom(
    D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV0, const D3DXVECTOR2 *pV1,
    const D3DXVECTOR2 *pV2, const D3DXVECTOR2 *pV3, float s );

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR2* WRAP_API D3DXVec2BaryCentric(
    D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2,
    const D3DXVECTOR2 *pV3, float f, float g);

// Transform (x, y, 0, 1) by matrix.
D3DXVECTOR4* WRAP_API D3DXVec2Transform(
    D3DXVECTOR4 *pOut, const D3DXVECTOR2 *pV, const D3DXMATRIX *pM);

// Transform (x, y, 0, 1) by matrix, project result back into w=1.
D3DXVECTOR2* WRAP_API D3DXVec2TransformCoord(
    D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV, const D3DXMATRIX *pM);

// Transform (x, y, 0, 0) by matrix.
D3DXVECTOR2* WRAP_API D3DXVec2TransformNormal(
    D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV, const D3DXMATRIX *pM);
     
// Transform Array (x, y, 0, 1) by matrix.
D3DXVECTOR4* WRAP_API D3DXVec2TransformArray(
    D3DXVECTOR4 *pOut, uint32_t OutStride, const D3DXVECTOR2 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n);

// Transform Array (x, y, 0, 1) by matrix, project result back into w=1.
D3DXVECTOR2* WRAP_API D3DXVec2TransformCoordArray(
    D3DXVECTOR2 *pOut, uint32_t OutStride, const D3DXVECTOR2 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n);

// Transform Array (x, y, 0, 0) by matrix.
D3DXVECTOR2* WRAP_API D3DXVec2TransformNormalArray(
    D3DXVECTOR2 *pOut, uint32_t OutStride, const D3DXVECTOR2 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n);


///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR3
///////////////////////////////////////////////////////////////////////////////

inline float D3DXVec3Length(const D3DXVECTOR3 *pV)
{
    assert(pV != nullptr);
    return sqrtf(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z);
}

inline float D3DXVec3LengthSq(const D3DXVECTOR3 *pV)
{
    assert(pV != nullptr);
    return pV->x * pV->x + pV->y * pV->y + pV->z * pV->z;
}

inline float D3DXVec3Dot(const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2)
{
    assert(pV1 != nullptr);
    assert(pV2 != nullptr);
    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z;
}

inline D3DXVECTOR3* D3DXVec3Cross(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    D3DXVECTOR3 v;
    v.x = pV1->y * pV2->z - pV1->z * pV2->y;
    v.y = pV1->z * pV2->x - pV1->x * pV2->z;
    v.z = pV1->x * pV2->y - pV1->y * pV2->x;

    *pOut = v;
    return pOut;
}

inline D3DXVECTOR3* D3DXVec3Add(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = pV1->x + pV2->x;
    pOut->y = pV1->y + pV2->y;
    pOut->z = pV1->z + pV2->z;
    return pOut;
}

inline D3DXVECTOR3* D3DXVec3Subtract(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = pV1->x - pV2->x;
    pOut->y = pV1->y - pV2->y;
    pOut->z = pV1->z - pV2->z;
    return pOut;
}

// Minimize each component.  x = min(x1, x2), y = min(y1, y2), ...
inline D3DXVECTOR3* D3DXVec3Minimize(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = (pV1->x < pV2->x) ? pV1->x : pV2->x;
    pOut->y = (pV1->y < pV2->y) ? pV1->y : pV2->y;
    pOut->z = (pV1->z < pV2->z) ? pV1->z : pV2->z;
    return pOut;
}

// Maximize each component.  x = max(x1, x2), y = max(y1, y2), ...
inline D3DXVECTOR3* D3DXVec3Maximize(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = (pV1->x > pV2->x) ? pV1->x : pV2->x;
    pOut->y = (pV1->y > pV2->y) ? pV1->y : pV2->y;
    pOut->z = (pV1->z > pV2->z) ? pV1->z : pV2->z;
    return pOut;
}

inline D3DXVECTOR3* D3DXVec3Scale(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, float s)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    pOut->x = pV->x * s;
    pOut->y = pV->y * s;
    pOut->z = pV->z * s;
    return pOut;
}

// Linear interpolation. V1 + s(V2-V1)
inline D3DXVECTOR3* D3DXVec3Lerp(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2, float s)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = pV1->x + s * (pV2->x - pV1->x);
    pOut->y = pV1->y + s * (pV2->y - pV1->y);
    pOut->z = pV1->z + s * (pV2->z - pV1->z);
    return pOut;
}

D3DXVECTOR3* WRAP_API D3DXVec3Normalize(
    D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV);

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR3* WRAP_API D3DXVec3Hermite(
    D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pT1,
    const D3DXVECTOR3 *pV2, const D3DXVECTOR3 *pT2, float s);

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR3* WRAP_API D3DXVec3CatmullRom(
    D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV0, const D3DXVECTOR3 *pV1,
    const D3DXVECTOR3 *pV2, const D3DXVECTOR3 *pV3, float s);

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR3* WRAP_API D3DXVec3BaryCentric(
    D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2,
    const D3DXVECTOR3 *pV3, float f, float g);

// Transform (x, y, z, 1) by matrix.
D3DXVECTOR4* WRAP_API D3DXVec3Transform(
    D3DXVECTOR4 *pOut, const D3DXVECTOR3 *pV, const D3DXMATRIX *pM);

// Transform (x, y, z, 1) by matrix, project result back into w=1.
D3DXVECTOR3* WRAP_API D3DXVec3TransformCoord(
    D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DXMATRIX *pM);

// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a 
// non-affine matrix, the matrix you pass to this function should be the 
// transpose of the inverse of the matrix you would use to transform a coord.
D3DXVECTOR3* WRAP_API D3DXVec3TransformNormal(
    D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DXMATRIX *pM);

// Transform Array (x, y, z, 1) by matrix. 
D3DXVECTOR4* WRAP_API D3DXVec3TransformArray(
    D3DXVECTOR4 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n);

// Transform Array (x, y, z, 1) by matrix, project result back into w=1.
D3DXVECTOR3* WRAP_API D3DXVec3TransformCoordArray(
    D3DXVECTOR3 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n);

// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a 
// non-affine matrix, the matrix you pass to this function should be the 
// transpose of the inverse of the matrix you would use to transform a coord.
D3DXVECTOR3* WRAP_API D3DXVec3TransformNormalArray(
    D3DXVECTOR3 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n);

// Project vector from object space into screen space
D3DXVECTOR3* WRAP_API D3DXVec3Project(
    D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DVIEWPORT9 *pViewport,
    const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld);

// Project vector from screen space into object space
D3DXVECTOR3* WRAP_API D3DXVec3Unproject(
    D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DVIEWPORT9 *pViewport,
    const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld);
      
// Project vector Array from object space into screen space
D3DXVECTOR3* WRAP_API D3DXVec3ProjectArray(
    D3DXVECTOR3 *pOut, uint32_t OutStride,const D3DXVECTOR3 *pV, uint32_t VStride,const D3DVIEWPORT9 *pViewport,
    const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld, uint32_t n);

// Project vector Array from screen space into object space
D3DXVECTOR3* WRAP_API D3DXVec3UnprojectArray(
    D3DXVECTOR3 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DVIEWPORT9 *pViewport,
    const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld, uint32_t n);


///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR4
///////////////////////////////////////////////////////////////////////////////

inline float D3DXVec4Length(const D3DXVECTOR4 *pV)
{
    assert(pV != nullptr);
    return sqrtf(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z + pV->w * pV->w);
}

inline float D3DXVec4LengthSq(const D3DXVECTOR4 *pV)
{
    assert(pV != nullptr);
    return pV->x * pV->x + pV->y * pV->y + pV->z * pV->z + pV->w * pV->w;
}

inline float D3DXVec4Dot(const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2)
{
    assert(pV1 != nullptr);
    assert(pV2 != nullptr);
    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z + pV1->w * pV2->w;
}

inline D3DXVECTOR4* D3DXVec4Add(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = pV1->x + pV2->x;
    pOut->y = pV1->y + pV2->y;
    pOut->z = pV1->z + pV2->z;
    pOut->w = pV1->w + pV2->w;
    return pOut;
}

inline D3DXVECTOR4* D3DXVec4Subtract(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = pV1->x - pV2->x;
    pOut->y = pV1->y - pV2->y;
    pOut->z = pV1->z - pV2->z;
    pOut->w = pV1->w - pV2->w;
    return pOut;
}

// Minimize each component.  x = min(x1, x2), y = min(y1, y2), ...
inline D3DXVECTOR4* D3DXVec4Minimize(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = (pV1->x < pV2->x) ? pV1->x : pV2->x;
    pOut->y = (pV1->y < pV2->y) ? pV1->y : pV2->y;
    pOut->z = (pV1->z < pV2->z) ? pV1->z : pV2->z;
    pOut->w = (pV1->w < pV2->w) ? pV1->w : pV2->w;
    return pOut;
}

// Maximize each component.  x = max(x1, x2), y = max(y1, y2), ...
inline D3DXVECTOR4* D3DXVec4Maximize(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = (pV1->x > pV2->x) ? pV1->x : pV2->x;
    pOut->y = (pV1->y > pV2->y) ? pV1->y : pV2->y;
    pOut->z = (pV1->z > pV2->z) ? pV1->z : pV2->z;
    pOut->w = (pV1->w > pV2->w) ? pV1->w : pV2->w;
    return pOut;
}

inline D3DXVECTOR4* D3DXVec4Scale(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV, float s)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    pOut->x = pV->x * s;
    pOut->y = pV->y * s;
    pOut->z = pV->z * s;
    pOut->w = pV->w * s;
    return pOut;
}

// Linear interpolation. V1 + s(V2-V1)
inline D3DXVECTOR4* D3DXVec4Lerp(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2, float s)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    pOut->x = pV1->x + s * (pV2->x - pV1->x);
    pOut->y = pV1->y + s * (pV2->y - pV1->y);
    pOut->z = pV1->z + s * (pV2->z - pV1->z);
    pOut->w = pV1->w + s * (pV2->w - pV1->w);
    return pOut;
}

// Cross-product in 4 dimensions.
D3DXVECTOR4* WRAP_API D3DXVec4Cross(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2, const D3DXVECTOR4 *pV3);

D3DXVECTOR4* WRAP_API D3DXVec4Normalize(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV);

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR4* WRAP_API D3DXVec4Hermite(
    D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pT1,
    const D3DXVECTOR4 *pV2, const D3DXVECTOR4 *pT2, float s );

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR4* WRAP_API D3DXVec4CatmullRom(
    D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV0, const D3DXVECTOR4 *pV1,
    const D3DXVECTOR4 *pV2, const D3DXVECTOR4 *pV3, float s );

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR4* WRAP_API D3DXVec4BaryCentric(
    D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2,
     const D3DXVECTOR4 *pV3, float f, float g);

// Transform vector by matrix.
D3DXVECTOR4* WRAP_API D3DXVec4Transform(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV, const D3DXMATRIX *pM );
    
// Transform vector array by matrix.
D3DXVECTOR4* WRAP_API D3DXVec4TransformArray(
    D3DXVECTOR4 *pOut, uint32_t OutStride, const D3DXVECTOR4 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n);


//--------------------------
// 4D Matrix
//--------------------------

inline D3DXMATRIX* D3DXMatrixIdentity(D3DXMATRIX *pOut)
{
    assert(pOut != nullptr);
    pOut->m[0][1] = pOut->m[0][2] = pOut->m[0][3] =
    pOut->m[1][0] = pOut->m[1][2] = pOut->m[1][3] =
    pOut->m[2][0] = pOut->m[2][1] = pOut->m[2][3] =
    pOut->m[3][0] = pOut->m[3][1] = pOut->m[3][2] = 0.0f;

    pOut->m[0][0] = pOut->m[1][1] = pOut->m[2][2] = pOut->m[3][3] = 1.0f;
    return pOut;
}

inline bool D3DXMatrixIsIdentity(const D3DXMATRIX *pM)
{
    assert(pM != nullptr);
    return pM->m[0][0] == 1.0f && pM->m[0][1] == 0.0f && pM->m[0][2] == 0.0f && pM->m[0][3] == 0.0f &&
           pM->m[1][0] == 0.0f && pM->m[1][1] == 1.0f && pM->m[1][2] == 0.0f && pM->m[1][3] == 0.0f &&
           pM->m[2][0] == 0.0f && pM->m[2][1] == 0.0f && pM->m[2][2] == 1.0f && pM->m[2][3] == 0.0f &&
           pM->m[3][0] == 0.0f && pM->m[3][1] == 0.0f && pM->m[3][2] == 0.0f && pM->m[3][3] == 1.0f;
}

float WRAP_API D3DXMatrixDeterminant(const D3DXMATRIX *pM);

long WRAP_API D3DXMatrixDecompose(
    D3DXVECTOR3 *pOutScale, D3DXQUATERNION *pOutRotation, 
	D3DXVECTOR3 *pOutTranslation, const D3DXMATRIX *pM );

D3DXMATRIX* WRAP_API D3DXMatrixTranspose(
    D3DXMATRIX *pOut, const D3DXMATRIX *pM);

// Matrix multiplication.  The result represents the transformation M2
// followed by the transformation M1.  (Out = M1 * M2)
D3DXMATRIX* WRAP_API D3DXMatrixMultiply(
    D3DXMATRIX *pOut, const D3DXMATRIX *pM1, const D3DXMATRIX *pM2);

// Matrix multiplication, followed by a transpose. (Out = T(M1 * M2))
D3DXMATRIX* WRAP_API D3DXMatrixMultiplyTranspose(
    D3DXMATRIX *pOut, const D3DXMATRIX *pM1, const D3DXMATRIX *pM2);

// Calculate inverse of matrix.  Inversion my fail, in which case NULL will
// be returned.  The determinant of pM is also returned it pfDeterminant
// is non-NULL.
D3DXMATRIX* WRAP_API D3DXMatrixInverse(D3DXMATRIX *pOut, float *pDeterminant, const D3DXMATRIX *pM);

// Build a matrix which scales by (sx, sy, sz)
D3DXMATRIX* WRAP_API D3DXMatrixScaling(D3DXMATRIX *pOut, float sx, float sy, float sz);

// Build a matrix which translates by (x, y, z)
D3DXMATRIX* WRAP_API D3DXMatrixTranslation(D3DXMATRIX *pOut, float x, float y, float z);

// Build a matrix which rotates around the X axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationX(D3DXMATRIX *pOut, float Angle);

// Build a matrix which rotates around the Y axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationY(D3DXMATRIX *pOut, float Angle);

// Build a matrix which rotates around the Z axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationZ(D3DXMATRIX *pOut, float Angle);

// Build a matrix which rotates around an arbitrary axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationAxis(D3DXMATRIX *pOut, const D3DXVECTOR3 *pV, float Angle);

// Build a matrix from a quaternion
D3DXMATRIX* WRAP_API D3DXMatrixRotationQuaternion(D3DXMATRIX *pOut, const D3DXQUATERNION *pQ);

// Yaw around the Y axis, a pitch around the X axis,
// and a roll around the Z axis.
D3DXMATRIX* WRAP_API D3DXMatrixRotationYawPitchRoll(D3DXMATRIX *pOut, float Yaw, float Pitch, float Roll);

// Build transformation matrix.  NULL arguments are treated as identity.
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixTransformation(
    D3DXMATRIX *pOut, const D3DXVECTOR3 *pScalingCenter,
    const D3DXQUATERNION *pScalingRotation, const D3DXVECTOR3 *pScaling,
    const D3DXVECTOR3 *pRotationCenter, const D3DXQUATERNION *pRotation,
    const D3DXVECTOR3 *pTranslation);

// Build 2D transformation matrix in XY plane.  NULL arguments are treated as identity.
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixTransformation2D(
    D3DXMATRIX *pOut, const D3DXVECTOR2* pScalingCenter, 
    float ScalingRotation, const D3DXVECTOR2* pScaling, 
    const D3DXVECTOR2* pRotationCenter, float Rotation, 
    const D3DXVECTOR2* pTranslation);

// Build affine transformation matrix.  NULL arguments are treated as identity.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixAffineTransformation(
    D3DXMATRIX *pOut, float Scaling, const D3DXVECTOR3 *pRotationCenter,
    const D3DXQUATERNION *pRotation, const D3DXVECTOR3 *pTranslation);

// Build 2D affine transformation matrix in XY plane.  NULL arguments are treated as identity.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixAffineTransformation2D(
    D3DXMATRIX *pOut, float Scaling, const D3DXVECTOR2* pRotationCenter, 
    float Rotation, const D3DXVECTOR2* pTranslation);

// Build a lookat matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixLookAtRH(
    D3DXMATRIX *pOut, const D3DXVECTOR3 *pEye, const D3DXVECTOR3 *pAt, const D3DXVECTOR3 *pUp );

// Build a lookat matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixLookAtLH(
    D3DXMATRIX *pOut, const D3DXVECTOR3 *pEye, const D3DXVECTOR3 *pAt, const D3DXVECTOR3 *pUp );

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveRH(
    D3DXMATRIX *pOut, float w, float h, float zn, float zf);

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveLH(
    D3DXMATRIX *pOut, float w, float h, float zn, float zf);

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveFovRH(
    D3DXMATRIX *pOut, float fovy, float Aspect, float zn, float zf);

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveFovLH(
    D3DXMATRIX *pOut, float fovy, float Aspect, float zn, float zf);

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveOffCenterRH(
    D3DXMATRIX *pOut, float l, float r, float b, float t, float zn, float zf);

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveOffCenterLH
    ( D3DXMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf );

// Build an ortho projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoRH(
    D3DXMATRIX *pOut, float w, float h, float zn, float zf);

// Build an ortho projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoLH(
    D3DXMATRIX *pOut, float w, float h, float zn, float zf);

// Build an ortho projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoOffCenterRH(
    D3DXMATRIX *pOut, float l, float r, float b, float t, float zn, float zf);

// Build an ortho projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoOffCenterLH(
    D3DXMATRIX *pOut, float l, float r, float b, float t, float zn, float zf);

// Build a matrix which flattens geometry into a plane, as if casting
// a shadow from a light.
D3DXMATRIX* WRAP_API D3DXMatrixShadow(
    D3DXMATRIX *pOut, const D3DXVECTOR4 *pLight, const D3DXPLANE *pPlane);

// Build a matrix which reflects the coordinate system about a plane
D3DXMATRIX* WRAP_API D3DXMatrixReflect(D3DXMATRIX *pOut, const D3DXPLANE *pPlane);

//--------------------------
// Quaternion
//--------------------------

inline float D3DXQuaternionLength(const D3DXQUATERNION *pQ)
{
    assert(pQ != nullptr);
    return sqrtf(pQ->x * pQ->x + pQ->y * pQ->y + pQ->z * pQ->z + pQ->w * pQ->w);
}

// Length squared, or "norm"
inline float D3DXQuaternionLengthSq(const D3DXQUATERNION *pQ)
{
    assert(pQ != nullptr);
    return pQ->x * pQ->x + pQ->y * pQ->y + pQ->z * pQ->z + pQ->w * pQ->w;
}

inline float D3DXQuaternionDot(const D3DXQUATERNION *pQ1, const D3DXQUATERNION *pQ2)
{
    assert(pQ1 != nullptr);
    assert(pQ2 != nullptr);
    return pQ1->x * pQ2->x + pQ1->y * pQ2->y + pQ1->z * pQ2->z + pQ1->w * pQ2->w;
}

// (0, 0, 0, 1)
inline D3DXQUATERNION* D3DXQuaternionIdentity(D3DXQUATERNION *pOut)
{
    assert(pOut != nullptr);
    pOut->x = pOut->y = pOut->z = 0.0f;
    pOut->w = 1.0f;
    return pOut;
}

inline bool D3DXQuaternionIsIdentity(const D3DXQUATERNION *pQ)
{
    assert(pQ != nullptr);
    return pQ->x == 0.0f && pQ->y == 0.0f && pQ->z == 0.0f && pQ->w == 1.0f;
}

// (-x, -y, -z, w)
inline D3DXQUATERNION* D3DXQuaternionConjugate(D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ)
{
    assert(pOut != nullptr);
    assert(pQ   != nullptr);
    pOut->x = -pQ->x;
    pOut->y = -pQ->y;
    pOut->z = -pQ->z;
    pOut->w =  pQ->w;
    return pOut;
}

// Compute a quaternin's axis and angle of rotation. Expects unit quaternions.
void WRAP_API D3DXQuaternionToAxisAngle(
    const D3DXQUATERNION *pQ, D3DXVECTOR3 *pAxis, float *pAngle);

// Build a quaternion from a rotation matrix.
D3DXQUATERNION* WRAP_API D3DXQuaternionRotationMatrix(
    D3DXQUATERNION *pOut, const D3DXMATRIX *pM);

// Rotation about arbitrary axis.
D3DXQUATERNION* WRAP_API D3DXQuaternionRotationAxis(
    D3DXQUATERNION *pOut, const D3DXVECTOR3 *pV, float Angle);

// Yaw around the Y axis, a pitch around the X axis,
// and a roll around the Z axis.
D3DXQUATERNION* WRAP_API D3DXQuaternionRotationYawPitchRoll(
    D3DXQUATERNION *pOut, float Yaw, float Pitch, float Roll);

// Quaternion multiplication.  The result represents the rotation Q2
// followed by the rotation Q1.  (Out = Q2 * Q1)
D3DXQUATERNION* WRAP_API D3DXQuaternionMultiply(
    D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1, const D3DXQUATERNION *pQ2);

D3DXQUATERNION* WRAP_API D3DXQuaternionNormalize(
    D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ);

// Conjugate and re-norm
D3DXQUATERNION* WRAP_API D3DXQuaternionInverse(
    D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ);

// Expects unit quaternions.
// if q = (cos(theta), sin(theta) * v); ln(q) = (0, theta * v)
D3DXQUATERNION* WRAP_API D3DXQuaternionLn(
    D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ);

// Expects pure quaternions. (w == 0)  w is ignored in calculation.
// if q = (0, theta * v); exp(q) = (cos(theta), sin(theta) * v)
D3DXQUATERNION* WRAP_API D3DXQuaternionExp(
    D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ);
      
// Spherical linear interpolation between Q1 (t == 0) and Q2 (t == 1).
// Expects unit quaternions.
D3DXQUATERNION* WRAP_API D3DXQuaternionSlerp(
    D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1, const D3DXQUATERNION *pQ2, float t);

// Spherical quadrangle interpolation.
// Slerp(Slerp(Q1, C, t), Slerp(A, B, t), 2t(1-t))
D3DXQUATERNION* WRAP_API D3DXQuaternionSquad(
    D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1,
    const D3DXQUATERNION *pA, const D3DXQUATERNION *pB,
    const D3DXQUATERNION *pC, float t);

// Setup control points for spherical quadrangle interpolation
// from Q1 to Q2.  The control points are chosen in such a way 
// to ensure the continuity of tangents with adjacent segments.
void WRAP_API D3DXQuaternionSquadSetup(
    D3DXQUATERNION *pAOut, D3DXQUATERNION *pBOut, D3DXQUATERNION *pCOut,
    const D3DXQUATERNION *pQ0, const D3DXQUATERNION *pQ1, 
    const D3DXQUATERNION *pQ2, const D3DXQUATERNION *pQ3);

// Barycentric interpolation.
// Slerp(Slerp(Q1, Q2, f+g), Slerp(Q1, Q3, f+g), g/(f+g))
D3DXQUATERNION* WRAP_API D3DXQuaternionBaryCentric(
    D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1,
    const D3DXQUATERNION *pQ2, const D3DXQUATERNION *pQ3,
    float f, float g);

//--------------------------
// Plane
//--------------------------

// inline

// ax + by + cz + dw
inline float D3DXPlaneDot(const D3DXPLANE *pP, const D3DXVECTOR4 *pV)
{
    assert(pP != nullptr);
    assert(pV != nullptr);
    return pP->a * pV->x + pP->b * pV->y + pP->c * pV->z + pP->d * pV->w;
}

// ax + by + cz + d
inline float D3DXPlaneDotCoord(const D3DXPLANE *pP, const D3DXVECTOR3 *pV)
{
    assert(pP != nullptr);
    assert(pV != nullptr);
    return pP->a * pV->x + pP->b * pV->y + pP->c * pV->z + pP->d;
}

// ax + by + cz
inline float D3DXPlaneDotNormal(const D3DXPLANE *pP, const D3DXVECTOR3 *pV)
{
    assert(pP != nullptr);
    assert(pV != nullptr);
    return pP->a * pV->x + pP->b * pV->y + pP->c * pV->z;
}

inline D3DXPLANE* D3DXPlaneScale(D3DXPLANE *pOut, const D3DXPLANE *pP, float s)
{
    assert(pOut != nullptr);
    assert(pP   != nullptr);
    pOut->a = pP->a * s;
    pOut->b = pP->b * s;
    pOut->c = pP->c * s;
    pOut->d = pP->d * s;
    return pOut;
}

// Normalize plane (so that |a,b,c| == 1)
D3DXPLANE* WRAP_API D3DXPlaneNormalize(D3DXPLANE *pOut, const D3DXPLANE *pP);

// Find the intersection between a plane and a line.  If the line is
// parallel to the plane, NULL is returned.
D3DXVECTOR3* WRAP_API D3DXPlaneIntersectLine(
    D3DXVECTOR3 *pOut, const D3DXPLANE *pP, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2);

// Construct a plane from a point and a normal
D3DXPLANE* WRAP_API D3DXPlaneFromPointNormal(
    D3DXPLANE *pOut, const D3DXVECTOR3 *pPoint, const D3DXVECTOR3 *pNormal);

// Construct a plane from 3 points
D3DXPLANE* WRAP_API D3DXPlaneFromPoints(
    D3DXPLANE *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2, const D3DXVECTOR3 *pV3);

// Transform a plane by a matrix.  The vector (a,b,c) must be normal.
// M should be the inverse transpose of the transformation desired.
D3DXPLANE* WRAP_API D3DXPlaneTransform(
    D3DXPLANE *pOut, const D3DXPLANE *pP, const D3DXMATRIX *pM);
    
// Transform an array of planes by a matrix.  The vectors (a,b,c) must be normal.
// M should be the inverse transpose of the transformation desired.
D3DXPLANE* WRAP_API D3DXPlaneTransformArray(
    D3DXPLANE *pOut, uint32_t OutStride, const D3DXPLANE *pP, uint32_t PStride, const D3DXMATRIX *pM, uint32_t n);

//--------------------------
// Color
//--------------------------

// (1-r, 1-g, 1-b, a)
inline D3DXCOLOR* D3DXColorNegative(D3DXCOLOR *pOut, const D3DXCOLOR *pC)
{
    assert(pOut != nullptr);
    assert(pC   != nullptr);
    pOut->r = 1.0f - pC->r;
    pOut->g = 1.0f - pC->g;
    pOut->b = 1.0f - pC->b;
    pOut->a = pC->a;
    return pOut;
}

inline D3DXCOLOR* D3DXColorAdd(D3DXCOLOR *pOut, const D3DXCOLOR *pC1, const D3DXCOLOR *pC2)
{
    assert(pOut != nullptr);
    assert(pC1  != nullptr);
    assert(pC2  != nullptr);
    pOut->r = pC1->r + pC2->r;
    pOut->g = pC1->g + pC2->g;
    pOut->b = pC1->b + pC2->b;
    pOut->a = pC1->a + pC2->a;
    return pOut;
}

inline D3DXCOLOR* D3DXColorSubtract(D3DXCOLOR *pOut, const D3DXCOLOR *pC1, const D3DXCOLOR *pC2)
{
    assert(pOut != nullptr);
    assert(pC1  != nullptr);
    assert(pC2  != nullptr);
    pOut->r = pC1->r - pC2->r;
    pOut->g = pC1->g - pC2->g;
    pOut->b = pC1->b - pC2->b;
    pOut->a = pC1->a - pC2->a;
    return pOut;
}

inline D3DXCOLOR* D3DXColorScale(D3DXCOLOR *pOut, const D3DXCOLOR *pC, float s)
{
    assert(pOut != nullptr);
    assert(pC   != nullptr);
    pOut->r = pC->r * s;
    pOut->g = pC->g * s;
    pOut->b = pC->b * s;
    pOut->a = pC->a * s;
    return pOut;
}

// (r1*r2, g1*g2, b1*b2, a1*a2)
inline D3DXCOLOR* D3DXColorModulate(D3DXCOLOR *pOut, const D3DXCOLOR *pC1, const D3DXCOLOR *pC2)
{
    assert(pOut != nullptr);
    assert(pC1  != nullptr);
    assert(pC2  != nullptr);
    pOut->r = pC1->r * pC2->r;
    pOut->g = pC1->g * pC2->g;
    pOut->b = pC1->b * pC2->b;
    pOut->a = pC1->a * pC2->a;
    return pOut;
}

// Linear interpolation of r,g,b, and a. C1 + s(C2-C1)
inline D3DXCOLOR* D3DXColorLerp(D3DXCOLOR *pOut, const D3DXCOLOR *pC1, const D3DXCOLOR *pC2, float s)
{
    assert(pOut != nullptr);
    assert(pC1  != nullptr);
    assert(pC2  != nullptr);
    pOut->r = pC1->r + s * (pC2->r - pC1->r);
    pOut->g = pC1->g + s * (pC2->g - pC1->g);
    pOut->b = pC1->b + s * (pC2->b - pC1->b);
    pOut->a = pC1->a + s * (pC2->a - pC1->a);
    return pOut;
}

// Interpolate r,g,b between desaturated color and color.
// DesaturatedColor + s(Color - DesaturatedColor)
D3DXCOLOR* WRAP_API D3DXColorAdjustSaturation(
    D3DXCOLOR *pOut, const D3DXCOLOR *pC, float s);

// Interpolate r,g,b between 50% grey and color.  Grey + s(Color - Grey)
D3DXCOLOR* WRAP_API D3DXColorAdjustContrast(
    D3DXCOLOR *pOut, const D3DXCOLOR *pC, float c);
