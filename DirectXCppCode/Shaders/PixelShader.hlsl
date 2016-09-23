//--------------------------------------------------------------------------------------
struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
	float4 Normal: NORMAL;
	float4 color : COLOR0;
};
Texture2D  gTexture : register(t0);
SamplerState TextureSampler
{
	Filter = MIN_MAG_MIP_LINEAR;
};
//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 main( VS_OUTPUT input ) : SV_Target
{
	//float intens=mul(input.Normal,float4(0,-1,0,0));
	//float2 texturecoor;
	//texturecoor[0] = input.color[0];
	//texturecoor[1] = 1-input.color[1];
	//return gTexture.Sample(TextureSampler, texturecoor);
    return input.color;
}
