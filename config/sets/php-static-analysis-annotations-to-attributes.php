<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\Php80\ValueObject\AnnotationToAttribute;
use PhpStaticAnalysis\Attributes\IsReadOnly;
use PhpStaticAnalysis\Attributes\Param;
use PhpStaticAnalysis\Attributes\Property;
use PhpStaticAnalysis\Attributes\Returns;
use PhpStaticAnalysis\Attributes\Template;
use PhpStaticAnalysis\Attributes\Type;
use PhpStaticAnalysis\RectorRule\AnnotationsToAttributesRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->ruleWithConfiguration(
        AnnotationsToAttributesRector::class,
        [
            new AnnotationToAttribute('param', Param::class),
            new AnnotationToAttribute('property', Property::class),
            new AnnotationToAttribute('readonly', IsReadOnly::class),
            new AnnotationToAttribute('return', Returns::class),
            new AnnotationToAttribute('template', Template::class),
            new AnnotationToAttribute('var', Type::class),
            'addParamAttributeOnParameters' => false,
            'useTypeAttributeForReturnAnnotation' => false,
            'usePropertyAttributeForVarAnnotation' => false,
        ]
    );
};
