// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Test_CharacterCPP : ModuleRules
{
	public Test_CharacterCPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
