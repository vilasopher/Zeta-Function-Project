#!/usr/bin/env wolframscript

Print[ Abs[N[Zeta[ToExpression[$ScriptCommandLine[[2]]]], ToExpression[$ScriptCommandLine[[4]]] + 5] - ToExpression[$ScriptCommandLine[[3]]]] < 10^(- ToExpression[$ScriptCommandLine[[4]]]) ]
