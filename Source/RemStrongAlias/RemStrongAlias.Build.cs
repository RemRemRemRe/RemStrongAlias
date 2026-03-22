// Copyright RemRemRemRe. All Rights Reserved.

using System.IO;
using UnrealBuildTool;
using Rem.BuildRule;

public class RemStrongAlias : ModuleRules
{
	public RemStrongAlias(ReadOnlyTargetRules target) : base(target)
	{
        RemSharedModuleRules.Apply(this);

		PrivateDependencyModuleNames.AddRange(
			[
				"Core",
			]
		);
	}
}
