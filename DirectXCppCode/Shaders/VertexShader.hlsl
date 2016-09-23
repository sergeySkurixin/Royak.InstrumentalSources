//--------------------------------------------------------------------------------------
// Constant Buffer Variables
//--------------------------------------------------------------------------------------
cbuffer ConstantBuffer : register( b0 )
{
	matrix View;
	matrix Projection;
}
//--------------------------------------------------------------------------------------
struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
	float4 Normal: NORMAL;
	float4 color : COLOR0;
};
//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT main( float4 Pos : POSITION, float4 Color : COLOR , float3 Normal : NORMAL)
{
    VS_OUTPUT output = (VS_OUTPUT)0;
	output.Pos = Pos;

    output.Pos = mul( Pos, View );
    output.Pos = mul( output.Pos, Projection );
	output.Normal=mul( Normal, View );
	output.Normal=mul( output.Normal, Projection );
    output.color = Color;

	output.color = Pos;
	return output;
}
