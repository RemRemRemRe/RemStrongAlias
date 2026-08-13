// Copyright RemRemRemRe. 2026. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Modules/ModuleManager.h"

#include "strong_alias.h"

#if WITH_DEV_AUTOMATION_TESTS

namespace Rem::StrongAlias::Private
{
// Local strong aliases under test: RemStrongAlias re-exports the strong_alias
// third-party header for project-wide use.
STRONG_ALIAS_EXPLICIT_CONVERSION(FRemStrongAliasTestHealth, int32);
STRONG_ALIAS_EXPLICIT_CONVERSION(FRemStrongAliasTestMana, int32);
}

using Rem::StrongAlias::Private::FRemStrongAliasTestHealth;
using Rem::StrongAlias::Private::FRemStrongAliasTestMana;

DEFINE_SPEC(FRemStrongAliasTest, "Rem.StrongAlias.Module",
    EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter);

void FRemStrongAliasTest::Define()
{
    Describe(TEXT("Module"), [this]
    {
        It(TEXT("module should be loaded"), [this]
        {
            TestTrue(TEXT("loaded"), FModuleManager::Get().IsModuleLoaded(FName{TEXTVIEW("RemStrongAlias")}));
        });
    });

    Describe(TEXT("Strong alias"), [this]
    {
        It(TEXT("should construct from the underlying value and read back"), [this]
        {
            FRemStrongAliasTestHealth Health{42};

            TestEqual(TEXT("value"), Health.value, 42);
        });

        It(TEXT("should keep distinct aliases of the same underlying type incompatible"), [this]
        {
            FRemStrongAliasTestHealth Health{1};
            FRemStrongAliasTestMana Mana{2};

            // the underlying values differ; the point is both types coexist without
            // implicit cross-assignment
            static_assert(!std::is_convertible_v<FRemStrongAliasTestHealth, FRemStrongAliasTestMana>);
            TestEqual(TEXT("health"), Health.value, 1);
            TestEqual(TEXT("mana"), Mana.value, 2);
        });

        It(TEXT("should support arithmetic on the underlying value"), [this]
        {
            FRemStrongAliasTestHealth Health{40};
            Health += FRemStrongAliasTestHealth{2};

            TestEqual(TEXT("sum"), Health.value, 42);
        });
    });
}

#endif // WITH_DEV_AUTOMATION_TESTS
