<?php

namespace test\PhpStaticAnalysis\RectorRule\Fixture;

use PhpStaticAnalysis\Attributes\Param;

class ReturnsAttributeTest
{
    /**
     * @return string
     */
    public function getName()
    {
        return 'John';
    }

    /**
     * @deprecated
     * @return string
     */
    public function getMoreNames()
    {
        return 'Mike';
    }

    /**
     * @return string
     */
    #[Param(name:'string')]
    public function getAnotherName($name)
    {
        return "Hello " . $name;
    }
}

/**
 * @return string
 */
function getName()
{
    return "Ann";
}

?>
-----
<?php

namespace test\PhpStaticAnalysis\RectorRule\Fixture;

use PhpStaticAnalysis\Attributes\Param;

class ReturnsAttributeTest
{
    #[\PhpStaticAnalysis\Attributes\Returns('string')]
    public function getName()
    {
        return 'John';
    }

    /**
     * @deprecated
     */
    #[\PhpStaticAnalysis\Attributes\Returns('string')]
    public function getMoreNames()
    {
        return 'Mike';
    }

    #[Param(name:'string')]
    #[\PhpStaticAnalysis\Attributes\Returns('string')]
    public function getAnotherName($name)
    {
        return "Hello " . $name;
    }
}

#[\PhpStaticAnalysis\Attributes\Returns('string')]
function getName()
{
    return "Ann";
}

?>