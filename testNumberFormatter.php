<?php

$usFormatter = new NumberFormatter('en-US', NumberFormatter::CURRENCY);
$usFormatter->setAttribute(NumberFormatter::FRACTION_DIGITS, 0);

echo $usFormatter->formatCurrency(45, 'USD') . PHP_EOL;
echo $usFormatter->formatCurrency(45, 'EUR') . PHP_EOL;

$frFormatter = new NumberFormatter('fr-FR', NumberFormatter::CURRENCY);
$frFormatter->setAttribute(NumberFormatter::FRACTION_DIGITS, 0);

echo $frFormatter->formatCurrency(45, 'EUR') . PHP_EOL;
echo $frFormatter->formatCurrency(45, 'USD') . PHP_EOL;
