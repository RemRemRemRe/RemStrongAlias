// Copyright RemRemRemRe. 2026. All Rights Reserved.

using UnrealBuildTool;
using Rem.BuildRule;

public class RemStrongAliasTest : ModuleRules
{
	public RemStrongAliasTest(ReadOnlyTargetRules target) : base(target)
	{
		RemSharedModuleRules.Apply(this);

		PrivateDependencyModuleNames.AddRange(
			[
				"Core",

				"RemCommon",
				"RemStrongAlias",
				"strong_alias",
			]
		);
	}
}
