//-----------------------------------------------------------------------------
// File : d3dx9math_wrapper.h
// Desc : Wrapper for d3dx9math
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <d3d9types.h>

#ifndef WRAP_API
#define WRAP_API
#endif//WRAP_API

#define D3DX_PI     DirectX::XM_PI
#define D3DX_1BYPI  DirectX::XM_1DIVPI

#ifdef USE_WRAP_NAMESPACE
namespace Wrapper {
#endif//USE_WRAP_NAMESPACE

inline float D3DXToRadian(float degree)
{ return DirectX::XMConvertToRadians(degree); }

inline float D3DXToDegree(float radian)
{ return DirectX::XMConvertToDegrees(radian); }

using D3DXFLOAT16 = DirectX::PackedVector::HALF;

//--------------------------
// 2D Vector
//--------------------------
struct D3DXVECTOR2 : public DirectX::XMFLOAT2
{
public:
    D3DXVECTOR2() {};
    D3DXVECTOR2( const float * );
    D3DXVECTOR2( const D3DXFLOAT16 * );
    D3DXVECTOR2( float x, float y );

    // casting
    operator float* ();
    operator const float* () const;

    // assignment operators
    D3DXVECTOR2& operator += ( const D3DXVECTOR2& );
    D3DXVECTOR2& operator -= ( const D3DXVECTOR2& );
    D3DXVECTOR2& operator *= ( float );
    D3DXVECTOR2& operator /= ( float );

    // unary operators
    D3DXVECTOR2 operator + () const;
    D3DXVECTOR2 operator - () const;

    // binary operators
    D3DXVECTOR2 operator + ( const D3DXVECTOR2& ) const;
    D3DXVECTOR2 operator - ( const D3DXVECTOR2& ) const;
    D3DXVECTOR2 operator * ( float ) const;
    D3DXVECTOR2 operator / ( float ) const;

    friend D3DXVECTOR2 operator * ( float, const D3DXVECTOR2& );

    bool operator == ( const D3DXVECTOR2& ) const;
    bool operator != ( const D3DXVECTOR2& ) const;
};

struct D3DXVECTOR2_16F
{
public:
    D3DXVECTOR2_16F() {};
    D3DXVECTOR2_16F( const float * );
    D3DXVECTOR2_16F( const D3DXFLOAT16 * );
    D3DXVECTOR2_16F( const D3DXFLOAT16 &x, const D3DXFLOAT16 &y );

    // casting
    operator D3DXFLOAT16* ();
    operator const D3DXFLOAT16* () const;

    // binary operators
    bool operator == ( const D3DXVECTOR2_16F& ) const;
    bool operator != ( const D3DXVECTOR2_16F& ) const;

public:
    D3DXFLOAT16 x, y;
};


//--------------------------
// 3D Vector
//--------------------------
struct D3DXVECTOR3 : public DirectX::XMFLOAT3
{
public:
    D3DXVECTOR3() {};
    D3DXVECTOR3( const float * );
    D3DXVECTOR3( const DirectX::XMFLOAT3& );
    D3DXVECTOR3( const D3DXFLOAT16 * );
    D3DXVECTOR3( float x, float y, float z );

    // casting
    operator float* ();
    operator const float* () const;

    // assignment operators
    D3DXVECTOR3& operator += ( const D3DXVECTOR3& );
    D3DXVECTOR3& operator -= ( const D3DXVECTOR3& );
    D3DXVECTOR3& operator *= ( float );
    D3DXVECTOR3& operator /= ( float );

    // unary operators
    D3DXVECTOR3 operator + () const;
    D3DXVECTOR3 operator - () const;

    // binary operators
    D3DXVECTOR3 operator + ( const D3DXVECTOR3& ) const;
    D3DXVECTOR3 operator - ( const D3DXVECTOR3& ) const;
    D3DXVECTOR3 operator * ( float ) const;
    D3DXVECTOR3 operator / ( float ) const;

    friend D3DXVECTOR3 operator * ( float, const struct D3DXVECTOR3& );

    bool operator == ( const D3DXVECTOR3& ) const;
    bool operator != ( const D3DXVECTOR3& ) const;
};

//--------------------------
// 3D Vector (16 bit)
//--------------------------
struct D3DXVECTOR3_16F
{
public:
    D3DXVECTOR3_16F() {};
    D3DXVECTOR3_16F( const float * );
    D3DXVECTOR3_16F( const DirectX::XMFLOAT3& );
    D3DXVECTOR3_16F( const D3DXFLOAT16 * );
    D3DXVECTOR3_16F( const D3DXFLOAT16 &x, const D3DXFLOAT16 &y, const D3DXFLOAT16 &z );

    // casting
    operator D3DXFLOAT16* ();
    operator const D3DXFLOAT16* () const;

    // binary operators
    bool operator == ( const D3DXVECTOR3_16F& ) const;
    bool operator != ( const D3DXVECTOR3_16F& ) const;

public:
    D3DXFLOAT16 x, y, z;
};


//--------------------------
// 4D Vector
//--------------------------
struct D3DXVECTOR4 : public DirectX::XMFLOAT4
{
public:
    D3DXVECTOR4() {};
    D3DXVECTOR4( const float* );
    D3DXVECTOR4( const D3DXFLOAT16* );
    D3DXVECTOR4( const DirectX::XMFLOAT3& xyz, float w );
    D3DXVECTOR4( float x, float y, float z, float w );

    // casting
    operator float* ();
    operator const float* () const;

    // assignment operators
    D3DXVECTOR4& operator += ( const D3DXVECTOR4& );
    D3DXVECTOR4& operator -= ( const D3DXVECTOR4& );
    D3DXVECTOR4& operator *= ( float );
    D3DXVECTOR4& operator /= ( float );

    // unary operators
    D3DXVECTOR4 operator + () const;
    D3DXVECTOR4 operator - () const;

    // binary operators
    D3DXVECTOR4 operator + ( const D3DXVECTOR4& ) const;
    D3DXVECTOR4 operator - ( const D3DXVECTOR4& ) const;
    D3DXVECTOR4 operator * ( float ) const;
    D3DXVECTOR4 operator / ( float ) const;

    friend D3DXVECTOR4 operator * ( float, const D3DXVECTOR4& );

    bool operator == ( const D3DXVECTOR4& ) const;
    bool operator != ( const D3DXVECTOR4& ) const;
};

//--------------------------
// 4D Vector (16 bit)
//--------------------------
struct D3DXVECTOR4_16F
{
public:
    D3DXVECTOR4_16F() {};
    D3DXVECTOR4_16F( const float * );
    D3DXVECTOR4_16F( const D3DXFLOAT16* );
    D3DXVECTOR4_16F( const D3DXVECTOR3_16F& xyz, const D3DXFLOAT16& w );
    D3DXVECTOR4_16F( const D3DXFLOAT16& x, const D3DXFLOAT16& y, const D3DXFLOAT16& z, const D3DXFLOAT16& w );

    // casting
    operator D3DXFLOAT16* ();
    operator const D3DXFLOAT16* () const;

    // binary operators
    bool operator == ( const D3DXVECTOR4_16F& ) const;
    bool operator != ( const D3DXVECTOR4_16F& ) const;

public:
    D3DXFLOAT16 x, y, z, w;
};

struct D3DXMATRIX : public DirectX::XMFLOAT4X4
{
public:
    D3DXMATRIX() {};
    D3DXMATRIX( const float * );
    D3DXMATRIX( const DirectX::XMFLOAT4X4& );
    D3DXMATRIX( const D3DXFLOAT16 * );
    D3DXMATRIX( float _11, float _12, float _13, float _14,
                float _21, float _22, float _23, float _24,
                float _31, float _32, float _33, float _34,
                float _41, float _42, float _43, float _44 );


    // access grants
    float& operator () ( uint32_t Row, uint32_t Col );
    float  operator () ( uint32_t Row, uint32_t Col ) const;

    // casting operators
    operator float* ();
    operator const float* () const;

    // assignment operators
    D3DXMATRIX& operator *= ( const D3DXMATRIX& );
    D3DXMATRIX& operator += ( const D3DXMATRIX& );
    D3DXMATRIX& operator -= ( const D3DXMATRIX& );
    D3DXMATRIX& operator *= ( float );
    D3DXMATRIX& operator /= ( float );

    // unary operators
    D3DXMATRIX operator + () const;
    D3DXMATRIX operator - () const;

    // binary operators
    D3DXMATRIX operator * ( const D3DXMATRIX& ) const;
    D3DXMATRIX operator + ( const D3DXMATRIX& ) const;
    D3DXMATRIX operator - ( const D3DXMATRIX& ) const;
    D3DXMATRIX operator * ( float ) const;
    D3DXMATRIX operator / ( float ) const;

    friend D3DXMATRIX operator * ( float, const D3DXMATRIX& );

    bool operator == ( const D3DXMATRIX& ) const;
    bool operator != ( const D3DXMATRIX& ) const;

};

struct D3DXMATRIXA16 : public D3DXMATRIX
{
    D3DXMATRIXA16() {}
    D3DXMATRIXA16( const float * );
    D3DXMATRIXA16( const D3DMATRIX& );
    D3DXMATRIXA16( const D3DXFLOAT16 * );
    D3DXMATRIXA16( float _11, float _12, float _13, float _14,
                    float _21, float _22, float _23, float _24,
                    float _31, float _32, float _33, float _34,
                    float _41, float _42, float _43, float _44 );

    // new operators
    void* operator new   ( size_t );
    void* operator new[] ( size_t );

    // delete operators
    void operator delete   ( void* );   // These are NOT virtual; Do not 
    void operator delete[] ( void* );   // cast to D3DXMATRIX and delete.
    
    // assignment operators
    D3DXMATRIXA16& operator = ( const D3DXMATRIX& );

};

struct D3DXQUATERNION : public DirectX::XMFLOAT4
{
public:
    D3DXQUATERNION() {}
    D3DXQUATERNION( const float * );
    D3DXQUATERNION( const D3DXFLOAT16 * );
    D3DXQUATERNION( float x, float y, float z, float w );

    // casting
    operator float* ();
    operator const float* () const;

    // assignment operators
    D3DXQUATERNION& operator += ( const D3DXQUATERNION& );
    D3DXQUATERNION& operator -= ( const D3DXQUATERNION& );
    D3DXQUATERNION& operator *= ( const D3DXQUATERNION& );
    D3DXQUATERNION& operator *= ( float );
    D3DXQUATERNION& operator /= ( float );

    // unary operators
    D3DXQUATERNION  operator + () const;
    D3DXQUATERNION  operator - () const;

    // binary operators
    D3DXQUATERNION operator + ( const D3DXQUATERNION& ) const;
    D3DXQUATERNION operator - ( const D3DXQUATERNION& ) const;
    D3DXQUATERNION operator * ( const D3DXQUATERNION& ) const;
    D3DXQUATERNION operator * ( float ) const;
    D3DXQUATERNION operator / ( float ) const;

    friend D3DXQUATERNION operator * (float, const D3DXQUATERNION& );

    bool operator == ( const D3DXQUATERNION& ) const;
    bool operator != ( const D3DXQUATERNION& ) const;

};

struct D3DXPLANE 
{
public:
    D3DXPLANE() {}
    D3DXPLANE( const float* );
    D3DXPLANE( const D3DXFLOAT16* );
    D3DXPLANE( float a, float b, float c, float d );

    // casting
    operator float* ();
    operator const float* () const;

    // assignment operators
    D3DXPLANE& operator *= ( float );
    D3DXPLANE& operator /= ( float );

    // unary operators
    D3DXPLANE operator + () const;
    D3DXPLANE operator - () const;

    // binary operators
    D3DXPLANE operator * ( float ) const;
    D3DXPLANE operator / ( float ) const;

    friend D3DXPLANE operator * ( float, const D3DXPLANE& );

    bool operator == ( const D3DXPLANE& ) const;
    bool operator != ( const D3DXPLANE& ) const;

    float a, b, c, d;
};

struct D3DXCOLOR
{
public:
    D3DXCOLOR() {}
    D3DXCOLOR( uint32_t argb );
    D3DXCOLOR( const float * );
    D3DXCOLOR( const D3DXFLOAT16 * );
    D3DXCOLOR( const D3DCOLORVALUE& );
    D3DXCOLOR( float r, float g, float b, float a );

    // casting
    operator uint32_t () const;

    operator float* ();
    operator const float* () const;

    operator D3DCOLORVALUE* ();
    operator const D3DCOLORVALUE* () const;

    operator D3DCOLORVALUE& ();
    operator const D3DCOLORVALUE& () const;

    // assignment operators
    D3DXCOLOR& operator += ( const D3DXCOLOR& );
    D3DXCOLOR& operator -= ( const D3DXCOLOR& );
    D3DXCOLOR& operator *= ( float );
    D3DXCOLOR& operator /= ( float );

    // unary operators
    D3DXCOLOR operator + () const;
    D3DXCOLOR operator - () const;

    // binary operators
    D3DXCOLOR operator + ( const D3DXCOLOR& ) const;
    D3DXCOLOR operator - ( const D3DXCOLOR& ) const;
    D3DXCOLOR operator * ( float ) const;
    D3DXCOLOR operator / ( float ) const;

    friend D3DXCOLOR operator * ( float, const D3DXCOLOR& );

    bool operator == ( const D3DXCOLOR& ) const;
    bool operator != ( const D3DXCOLOR& ) const;

    float r, g, b, a;
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

//--------------------------
// Float16
//--------------------------

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

// Converts an array 32-bit floats to 16-bit floats
D3DXFLOAT16* WRAP_API D3DXFloat32To16Array
    ( D3DXFLOAT16 *pOut, const float *pIn, uint32_t n );

// Converts an array 16-bit floats to 32-bit floats
float* WRAP_API D3DXFloat16To32Array
    ( float *pOut, const D3DXFLOAT16 *pIn, uint32_t n );

#ifdef __cplusplus
}
#endif


///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR2
///////////////////////////////////////////////////////////////////////////////

// inline

float D3DXVec2Length
    ( const D3DXVECTOR2 *pV );

float D3DXVec2LengthSq
    ( const D3DXVECTOR2 *pV );

float D3DXVec2Dot
    ( const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2 );

// Z component of ((x1,y1,0) cross (x2,y2,0))
float D3DXVec2CCW
    ( const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2 );

D3DXVECTOR2* D3DXVec2Add
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2 );

D3DXVECTOR2* D3DXVec2Subtract
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2 );

// Minimize each component.  x = min(x1, x2), y = min(y1, y2)
D3DXVECTOR2* D3DXVec2Minimize
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2 );

// Maximize each component.  x = max(x1, x2), y = max(y1, y2)
D3DXVECTOR2* D3DXVec2Maximize
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2 );

D3DXVECTOR2* D3DXVec2Scale
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV, float s );

// Linear interpolation. V1 + s(V2-V1)
D3DXVECTOR2* D3DXVec2Lerp
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2,
      float s );

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

D3DXVECTOR2* WRAP_API D3DXVec2Normalize
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV );

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR2* WRAP_API D3DXVec2Hermite
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pT1,
      const D3DXVECTOR2 *pV2, const D3DXVECTOR2 *pT2, float s );

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR2* WRAP_API D3DXVec2CatmullRom
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV0, const D3DXVECTOR2 *pV1,
      const D3DXVECTOR2 *pV2, const D3DXVECTOR2 *pV3, float s );

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR2* WRAP_API D3DXVec2BaryCentric
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2,
      const D3DXVECTOR2 *pV3, float f, float g);

// Transform (x, y, 0, 1) by matrix.
D3DXVECTOR4* WRAP_API D3DXVec2Transform
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR2 *pV, const D3DXMATRIX *pM );

// Transform (x, y, 0, 1) by matrix, project result back into w=1.
D3DXVECTOR2* WRAP_API D3DXVec2TransformCoord
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV, const D3DXMATRIX *pM );

// Transform (x, y, 0, 0) by matrix.
D3DXVECTOR2* WRAP_API D3DXVec2TransformNormal
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV, const D3DXMATRIX *pM );
     
// Transform Array (x, y, 0, 1) by matrix.
D3DXVECTOR4* WRAP_API D3DXVec2TransformArray
    ( D3DXVECTOR4 *pOut, uint32_t OutStride, const D3DXVECTOR2 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n);

// Transform Array (x, y, 0, 1) by matrix, project result back into w=1.
D3DXVECTOR2* WRAP_API D3DXVec2TransformCoordArray
    ( D3DXVECTOR2 *pOut, uint32_t OutStride, const D3DXVECTOR2 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n );

// Transform Array (x, y, 0, 0) by matrix.
D3DXVECTOR2* WRAP_API D3DXVec2TransformNormalArray
    ( D3DXVECTOR2 *pOut, uint32_t OutStride, const D3DXVECTOR2 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n );
    
    

#ifdef __cplusplus
}
#endif


///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR3
///////////////////////////////////////////////////////////////////////////////

// inline

float D3DXVec3Length
    ( const D3DXVECTOR3 *pV );

float D3DXVec3LengthSq
    ( const D3DXVECTOR3 *pV );

float D3DXVec3Dot
    ( const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2 );

D3DXVECTOR3* D3DXVec3Cross
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2 );

D3DXVECTOR3* D3DXVec3Add
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2 );

D3DXVECTOR3* D3DXVec3Subtract
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2 );

// Minimize each component.  x = min(x1, x2), y = min(y1, y2), ...
D3DXVECTOR3* D3DXVec3Minimize
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2 );

// Maximize each component.  x = max(x1, x2), y = max(y1, y2), ...
D3DXVECTOR3* D3DXVec3Maximize
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2 );

D3DXVECTOR3* D3DXVec3Scale
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, float s);

// Linear interpolation. V1 + s(V2-V1)
D3DXVECTOR3* D3DXVec3Lerp
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2,
      float s );

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

D3DXVECTOR3* WRAP_API D3DXVec3Normalize
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV );

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR3* WRAP_API D3DXVec3Hermite
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pT1,
      const D3DXVECTOR3 *pV2, const D3DXVECTOR3 *pT2, float s );

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR3* WRAP_API D3DXVec3CatmullRom
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV0, const D3DXVECTOR3 *pV1,
      const D3DXVECTOR3 *pV2, const D3DXVECTOR3 *pV3, float s );

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR3* WRAP_API D3DXVec3BaryCentric
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2,
      const D3DXVECTOR3 *pV3, float f, float g);

// Transform (x, y, z, 1) by matrix.
D3DXVECTOR4* WRAP_API D3DXVec3Transform
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR3 *pV, const D3DXMATRIX *pM );

// Transform (x, y, z, 1) by matrix, project result back into w=1.
D3DXVECTOR3* WRAP_API D3DXVec3TransformCoord
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DXMATRIX *pM );

// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a 
// non-affine matrix, the matrix you pass to this function should be the 
// transpose of the inverse of the matrix you would use to transform a coord.
D3DXVECTOR3* WRAP_API D3DXVec3TransformNormal
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DXMATRIX *pM );
    
    
// Transform Array (x, y, z, 1) by matrix. 
D3DXVECTOR4* WRAP_API D3DXVec3TransformArray
    ( D3DXVECTOR4 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n );

// Transform Array (x, y, z, 1) by matrix, project result back into w=1.
D3DXVECTOR3* WRAP_API D3DXVec3TransformCoordArray
    ( D3DXVECTOR3 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n );

// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a 
// non-affine matrix, the matrix you pass to this function should be the 
// transpose of the inverse of the matrix you would use to transform a coord.
D3DXVECTOR3* WRAP_API D3DXVec3TransformNormalArray
    ( D3DXVECTOR3 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n );

// Project vector from object space into screen space
D3DXVECTOR3* WRAP_API D3DXVec3Project
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DVIEWPORT9 *pViewport,
      const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld);

// Project vector from screen space into object space
D3DXVECTOR3* WRAP_API D3DXVec3Unproject
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DVIEWPORT9 *pViewport,
      const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld);
      
// Project vector Array from object space into screen space
D3DXVECTOR3* WRAP_API D3DXVec3ProjectArray
    ( D3DXVECTOR3 *pOut, uint32_t OutStride,const D3DXVECTOR3 *pV, uint32_t VStride,const D3DVIEWPORT9 *pViewport,
      const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld, uint32_t n);

// Project vector Array from screen space into object space
D3DXVECTOR3* WRAP_API D3DXVec3UnprojectArray
    ( D3DXVECTOR3 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DVIEWPORT9 *pViewport,
      const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld, uint32_t n);


#ifdef __cplusplus
}
#endif



///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR4
///////////////////////////////////////////////////////////////////////////////

// inline

float D3DXVec4Length
    ( const D3DXVECTOR4 *pV );

float D3DXVec4LengthSq
    ( const D3DXVECTOR4 *pV );

float D3DXVec4Dot
    ( const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2 );

D3DXVECTOR4* D3DXVec4Add
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2);

D3DXVECTOR4* D3DXVec4Subtract
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2);

// Minimize each component.  x = min(x1, x2), y = min(y1, y2), ...
D3DXVECTOR4* D3DXVec4Minimize
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2);

// Maximize each component.  x = max(x1, x2), y = max(y1, y2), ...
D3DXVECTOR4* D3DXVec4Maximize
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2);

D3DXVECTOR4* D3DXVec4Scale
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV, float s);

// Linear interpolation. V1 + s(V2-V1)
D3DXVECTOR4* D3DXVec4Lerp
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2,
      float s );

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

// Cross-product in 4 dimensions.
D3DXVECTOR4* WRAP_API D3DXVec4Cross
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2,
      const D3DXVECTOR4 *pV3);

D3DXVECTOR4* WRAP_API D3DXVec4Normalize
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV );

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR4* WRAP_API D3DXVec4Hermite
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pT1,
      const D3DXVECTOR4 *pV2, const D3DXVECTOR4 *pT2, float s );

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR4* WRAP_API D3DXVec4CatmullRom
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV0, const D3DXVECTOR4 *pV1,
      const D3DXVECTOR4 *pV2, const D3DXVECTOR4 *pV3, float s );

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR4* WRAP_API D3DXVec4BaryCentric
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2,
      const D3DXVECTOR4 *pV3, float f, float g);

// Transform vector by matrix.
D3DXVECTOR4* WRAP_API D3DXVec4Transform
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV, const D3DXMATRIX *pM );
    
// Transform vector array by matrix.
D3DXVECTOR4* WRAP_API D3DXVec4TransformArray
    ( D3DXVECTOR4 *pOut, uint32_t OutStride, const D3DXVECTOR4 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n );

#ifdef __cplusplus
}
#endif


//--------------------------
// 4D Matrix
//--------------------------

// inline

D3DXMATRIX* D3DXMatrixIdentity
    ( D3DXMATRIX *pOut );

bool D3DXMatrixIsIdentity
    ( const D3DXMATRIX *pM );


// non-inline
#ifdef __cplusplus
extern "C" {
#endif

float WRAP_API D3DXMatrixDeterminant
    ( const D3DXMATRIX *pM );

long WRAP_API D3DXMatrixDecompose
    ( D3DXVECTOR3 *pOutScale, D3DXQUATERNION *pOutRotation, 
	  D3DXVECTOR3 *pOutTranslation, const D3DXMATRIX *pM );

D3DXMATRIX* WRAP_API D3DXMatrixTranspose
    ( D3DXMATRIX *pOut, const D3DXMATRIX *pM );

// Matrix multiplication.  The result represents the transformation M2
// followed by the transformation M1.  (Out = M1 * M2)
D3DXMATRIX* WRAP_API D3DXMatrixMultiply
    ( D3DXMATRIX *pOut, const D3DXMATRIX *pM1, const D3DXMATRIX *pM2 );

// Matrix multiplication, followed by a transpose. (Out = T(M1 * M2))
D3DXMATRIX* WRAP_API D3DXMatrixMultiplyTranspose
    ( D3DXMATRIX *pOut, const D3DXMATRIX *pM1, const D3DXMATRIX *pM2 );

// Calculate inverse of matrix.  Inversion my fail, in which case NULL will
// be returned.  The determinant of pM is also returned it pfDeterminant
// is non-NULL.
D3DXMATRIX* WRAP_API D3DXMatrixInverse
    ( D3DXMATRIX *pOut, float *pDeterminant, const D3DXMATRIX *pM );

// Build a matrix which scales by (sx, sy, sz)
D3DXMATRIX* WRAP_API D3DXMatrixScaling
    ( D3DXMATRIX *pOut, float sx, float sy, float sz );

// Build a matrix which translates by (x, y, z)
D3DXMATRIX* WRAP_API D3DXMatrixTranslation
    ( D3DXMATRIX *pOut, float x, float y, float z );

// Build a matrix which rotates around the X axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationX
    ( D3DXMATRIX *pOut, float Angle );

// Build a matrix which rotates around the Y axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationY
    ( D3DXMATRIX *pOut, float Angle );

// Build a matrix which rotates around the Z axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationZ
    ( D3DXMATRIX *pOut, float Angle );

// Build a matrix which rotates around an arbitrary axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationAxis
    ( D3DXMATRIX *pOut, const D3DXVECTOR3 *pV, float Angle );

// Build a matrix from a quaternion
D3DXMATRIX* WRAP_API D3DXMatrixRotationQuaternion
    ( D3DXMATRIX *pOut, const D3DXQUATERNION *pQ);

// Yaw around the Y axis, a pitch around the X axis,
// and a roll around the Z axis.
D3DXMATRIX* WRAP_API D3DXMatrixRotationYawPitchRoll
    ( D3DXMATRIX *pOut, float Yaw, float Pitch, float Roll );

// Build transformation matrix.  NULL arguments are treated as identity.
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixTransformation
    ( D3DXMATRIX *pOut, const D3DXVECTOR3 *pScalingCenter,
      const D3DXQUATERNION *pScalingRotation, const D3DXVECTOR3 *pScaling,
      const D3DXVECTOR3 *pRotationCenter, const D3DXQUATERNION *pRotation,
      const D3DXVECTOR3 *pTranslation);

// Build 2D transformation matrix in XY plane.  NULL arguments are treated as identity.
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixTransformation2D
    ( D3DXMATRIX *pOut, const D3DXVECTOR2* pScalingCenter, 
      float ScalingRotation, const D3DXVECTOR2* pScaling, 
      const D3DXVECTOR2* pRotationCenter, float Rotation, 
      const D3DXVECTOR2* pTranslation);

// Build affine transformation matrix.  NULL arguments are treated as identity.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixAffineTransformation
    ( D3DXMATRIX *pOut, float Scaling, const D3DXVECTOR3 *pRotationCenter,
      const D3DXQUATERNION *pRotation, const D3DXVECTOR3 *pTranslation);

// Build 2D affine transformation matrix in XY plane.  NULL arguments are treated as identity.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixAffineTransformation2D
    ( D3DXMATRIX *pOut, float Scaling, const D3DXVECTOR2* pRotationCenter, 
      float Rotation, const D3DXVECTOR2* pTranslation);

// Build a lookat matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixLookAtRH
    ( D3DXMATRIX *pOut, const D3DXVECTOR3 *pEye, const D3DXVECTOR3 *pAt,
      const D3DXVECTOR3 *pUp );

// Build a lookat matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixLookAtLH
    ( D3DXMATRIX *pOut, const D3DXVECTOR3 *pEye, const D3DXVECTOR3 *pAt,
      const D3DXVECTOR3 *pUp );

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveRH
    ( D3DXMATRIX *pOut, float w, float h, float zn, float zf );

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveLH
    ( D3DXMATRIX *pOut, float w, float h, float zn, float zf );

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveFovRH
    ( D3DXMATRIX *pOut, float fovy, float Aspect, float zn, float zf );

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveFovLH
    ( D3DXMATRIX *pOut, float fovy, float Aspect, float zn, float zf );

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveOffCenterRH
    ( D3DXMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf );

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveOffCenterLH
    ( D3DXMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf );

// Build an ortho projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoRH
    ( D3DXMATRIX *pOut, float w, float h, float zn, float zf );

// Build an ortho projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoLH
    ( D3DXMATRIX *pOut, float w, float h, float zn, float zf );

// Build an ortho projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoOffCenterRH
    ( D3DXMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf );

// Build an ortho projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoOffCenterLH
    ( D3DXMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf );

// Build a matrix which flattens geometry into a plane, as if casting
// a shadow from a light.
D3DXMATRIX* WRAP_API D3DXMatrixShadow
    ( D3DXMATRIX *pOut, const D3DXVECTOR4 *pLight,
      const D3DXPLANE *pPlane );

// Build a matrix which reflects the coordinate system about a plane
D3DXMATRIX* WRAP_API D3DXMatrixReflect
    ( D3DXMATRIX *pOut, const D3DXPLANE *pPlane );

#ifdef __cplusplus
}
#endif


//--------------------------
// Quaternion
//--------------------------

// inline

float D3DXQuaternionLength
    ( const D3DXQUATERNION *pQ );

// Length squared, or "norm"
float D3DXQuaternionLengthSq
    ( const D3DXQUATERNION *pQ );

float D3DXQuaternionDot
    ( const D3DXQUATERNION *pQ1, const D3DXQUATERNION *pQ2 );

// (0, 0, 0, 1)
D3DXQUATERNION* D3DXQuaternionIdentity
    ( D3DXQUATERNION *pOut );

bool D3DXQuaternionIsIdentity
    ( const D3DXQUATERNION *pQ );

// (-x, -y, -z, w)
D3DXQUATERNION* D3DXQuaternionConjugate
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ );


// non-inline
#ifdef __cplusplus
extern "C" {
#endif

// Compute a quaternin's axis and angle of rotation. Expects unit quaternions.
void WRAP_API D3DXQuaternionToAxisAngle
    ( const D3DXQUATERNION *pQ, D3DXVECTOR3 *pAxis, float *pAngle );

// Build a quaternion from a rotation matrix.
D3DXQUATERNION* WRAP_API D3DXQuaternionRotationMatrix
    ( D3DXQUATERNION *pOut, const D3DXMATRIX *pM);

// Rotation about arbitrary axis.
D3DXQUATERNION* WRAP_API D3DXQuaternionRotationAxis
    ( D3DXQUATERNION *pOut, const D3DXVECTOR3 *pV, float Angle );

// Yaw around the Y axis, a pitch around the X axis,
// and a roll around the Z axis.
D3DXQUATERNION* WRAP_API D3DXQuaternionRotationYawPitchRoll
    ( D3DXQUATERNION *pOut, float Yaw, float Pitch, float Roll );

// Quaternion multiplication.  The result represents the rotation Q2
// followed by the rotation Q1.  (Out = Q2 * Q1)
D3DXQUATERNION* WRAP_API D3DXQuaternionMultiply
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1,
      const D3DXQUATERNION *pQ2 );

D3DXQUATERNION* WRAP_API D3DXQuaternionNormalize
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ );

// Conjugate and re-norm
D3DXQUATERNION* WRAP_API D3DXQuaternionInverse
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ );

// Expects unit quaternions.
// if q = (cos(theta), sin(theta) * v); ln(q) = (0, theta * v)
D3DXQUATERNION* WRAP_API D3DXQuaternionLn
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ );

// Expects pure quaternions. (w == 0)  w is ignored in calculation.
// if q = (0, theta * v); exp(q) = (cos(theta), sin(theta) * v)
D3DXQUATERNION* WRAP_API D3DXQuaternionExp
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ );
      
// Spherical linear interpolation between Q1 (t == 0) and Q2 (t == 1).
// Expects unit quaternions.
D3DXQUATERNION* WRAP_API D3DXQuaternionSlerp
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1,
      const D3DXQUATERNION *pQ2, float t );

// Spherical quadrangle interpolation.
// Slerp(Slerp(Q1, C, t), Slerp(A, B, t), 2t(1-t))
D3DXQUATERNION* WRAP_API D3DXQuaternionSquad
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1,
      const D3DXQUATERNION *pA, const D3DXQUATERNION *pB,
      const D3DXQUATERNION *pC, float t );

// Setup control points for spherical quadrangle interpolation
// from Q1 to Q2.  The control points are chosen in such a way 
// to ensure the continuity of tangents with adjacent segments.
void WRAP_API D3DXQuaternionSquadSetup
    ( D3DXQUATERNION *pAOut, D3DXQUATERNION *pBOut, D3DXQUATERNION *pCOut,
      const D3DXQUATERNION *pQ0, const D3DXQUATERNION *pQ1, 
      const D3DXQUATERNION *pQ2, const D3DXQUATERNION *pQ3 );

// Barycentric interpolation.
// Slerp(Slerp(Q1, Q2, f+g), Slerp(Q1, Q3, f+g), g/(f+g))
D3DXQUATERNION* WRAP_API D3DXQuaternionBaryCentric
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1,
      const D3DXQUATERNION *pQ2, const D3DXQUATERNION *pQ3,
      float f, float g );

#ifdef __cplusplus
}
#endif


//--------------------------
// Plane
//--------------------------

// inline

// ax + by + cz + dw
float D3DXPlaneDot
    ( const D3DXPLANE *pP, const D3DXVECTOR4 *pV);

// ax + by + cz + d
float D3DXPlaneDotCoord
    ( const D3DXPLANE *pP, const D3DXVECTOR3 *pV);

// ax + by + cz
float D3DXPlaneDotNormal
    ( const D3DXPLANE *pP, const D3DXVECTOR3 *pV);

D3DXPLANE* D3DXPlaneScale
    (D3DXPLANE *pOut, const D3DXPLANE *pP, float s);

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

// Normalize plane (so that |a,b,c| == 1)
D3DXPLANE* WRAP_API D3DXPlaneNormalize
    ( D3DXPLANE *pOut, const D3DXPLANE *pP);

// Find the intersection between a plane and a line.  If the line is
// parallel to the plane, NULL is returned.
D3DXVECTOR3* WRAP_API D3DXPlaneIntersectLine
    ( D3DXVECTOR3 *pOut, const D3DXPLANE *pP, const D3DXVECTOR3 *pV1,
      const D3DXVECTOR3 *pV2);

// Construct a plane from a point and a normal
D3DXPLANE* WRAP_API D3DXPlaneFromPointNormal
    ( D3DXPLANE *pOut, const D3DXVECTOR3 *pPoint, const D3DXVECTOR3 *pNormal);

// Construct a plane from 3 points
D3DXPLANE* WRAP_API D3DXPlaneFromPoints
    ( D3DXPLANE *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2,
      const D3DXVECTOR3 *pV3);

// Transform a plane by a matrix.  The vector (a,b,c) must be normal.
// M should be the inverse transpose of the transformation desired.
D3DXPLANE* WRAP_API D3DXPlaneTransform
    ( D3DXPLANE *pOut, const D3DXPLANE *pP, const D3DXMATRIX *pM );
    
// Transform an array of planes by a matrix.  The vectors (a,b,c) must be normal.
// M should be the inverse transpose of the transformation desired.
D3DXPLANE* WRAP_API D3DXPlaneTransformArray
    ( D3DXPLANE *pOut, uint32_t OutStride, const D3DXPLANE *pP, uint32_t PStride, const D3DXMATRIX *pM, uint32_t n );

#ifdef __cplusplus
}
#endif


//--------------------------
// Color
//--------------------------

// inline

// (1-r, 1-g, 1-b, a)
D3DXCOLOR* D3DXColorNegative
    (D3DXCOLOR *pOut, const D3DXCOLOR *pC);

D3DXCOLOR* D3DXColorAdd
    (D3DXCOLOR *pOut, const D3DXCOLOR *pC1, const D3DXCOLOR *pC2);

D3DXCOLOR* D3DXColorSubtract
    (D3DXCOLOR *pOut, const D3DXCOLOR *pC1, const D3DXCOLOR *pC2);

D3DXCOLOR* D3DXColorScale
    (D3DXCOLOR *pOut, const D3DXCOLOR *pC, float s);

// (r1*r2, g1*g2, b1*b2, a1*a2)
D3DXCOLOR* D3DXColorModulate
    (D3DXCOLOR *pOut, const D3DXCOLOR *pC1, const D3DXCOLOR *pC2);

// Linear interpolation of r,g,b, and a. C1 + s(C2-C1)
D3DXCOLOR* D3DXColorLerp
    (D3DXCOLOR *pOut, const D3DXCOLOR *pC1, const D3DXCOLOR *pC2, float s);

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

// Interpolate r,g,b between desaturated color and color.
// DesaturatedColor + s(Color - DesaturatedColor)
D3DXCOLOR* WRAP_API D3DXColorAdjustSaturation
    (D3DXCOLOR *pOut, const D3DXCOLOR *pC, float s);

// Interpolate r,g,b between 50% grey and color.  Grey + s(Color - Grey)
D3DXCOLOR* WRAP_API D3DXColorAdjustContrast
    (D3DXCOLOR *pOut, const D3DXCOLOR *pC, float c);

#ifdef __cplusplus
}
#endif


#ifdef USE_WRAP_NAMESPACE
} // namespace Wrapper
#endif//USE_WRAP_NAMESPACE
