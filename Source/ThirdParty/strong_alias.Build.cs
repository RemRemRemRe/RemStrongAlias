// Copyright RemRemRemRe. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class strong_alias : ModuleRules
{
	public strong_alias(ReadOnlyTargetRules target) : base(target)
	{
		Type = ModuleType.External;

		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "strong_alias"));
	}
}
